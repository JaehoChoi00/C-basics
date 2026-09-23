#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "../variables/VariableConstants.h"

void *waitingWorker(void *arg);
void *signalingWorker(void *arg);
void *tryLockExample(void *arg);
void *datasetReader(void *arg);
void *datasetWriter(void *arg);

pthread_mutex_t logMutex = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t condMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t conditionVariable = PTHREAD_COND_INITIALIZER;
int dataReady = 0;

pthread_mutex_t trylockMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t recursiveMutex; 

pthread_rwlock_t readerWriterLock = PTHREAD_RWLOCK_INITIALIZER;
int sharedDataset = 64;

void safe_log(const char* color, const char* formatStringMessage, const char* thread_name, int extraFormatValue) {
    struct timespec timeSpec;
    struct tm localTime;
    
    if (timespec_get(&timeSpec, TIME_UTC)) {
        localtime_r(&timeSpec.tv_sec, &localTime);
        long milliseconds = timeSpec.tv_nsec / 1000000;
        
        pthread_mutex_lock(&logMutex);
        printf("%sCurrent time: [%02d:%02d:%02d.%03ld]" BOLD FG_WHITE " | ", 
            color, localTime.tm_hour, localTime.tm_min, localTime.tm_sec, milliseconds);
        
        if (extraFormatValue != -1) {
            printf(formatStringMessage, thread_name, extraFormatValue);
        } else {
            printf(formatStringMessage, thread_name);
        }
        printf(RESET);
        pthread_mutex_unlock(&logMutex);
    }
}

void *waitingWorker(void *arg) {
    safe_log(FG_CYAN, "Running %s -> Waiting for condition predicate...\n", (char *)arg, -1);
    
    pthread_mutex_lock(&condMutex);
    while (dataReady == 0) {
        pthread_cond_wait(&conditionVariable, &condMutex);
    }
    pthread_mutex_unlock(&condMutex);
    
    safe_log(FG_GREEN, "Exiting %s -> Predicate met! Woken up successfully.\n", (char *)arg, -1);
    return NULL;
}

void *signalingWorker(void *arg) {
    safe_log(FG_MAGENTA, "Running %s -> Sleeping for 2 seconds before signaling...\n", (char *)arg, -1);
    sleep(2);
    
    pthread_mutex_lock(&condMutex);
    dataReady = 1;
    pthread_mutex_unlock(&condMutex);
    
    pthread_cond_signal(&conditionVariable);
    safe_log(FG_GREEN, "Exiting %s -> Condition signal broadcasted.\n", (char *)arg, -1);
    return NULL;
}

void *tryLockExample(void *arg) {
    safe_log(FG_BLUE, "Running %s -> Attempting non-blocking lock...\n", (char *)arg, -1);
    
    if (pthread_mutex_trylock(&trylockMutex) == 0) {
        safe_log(FG_GREEN, "Success %s -> Acquired trylockMutex! Working for 1 second...\n", (char *)arg, -1);
        sleep(1);
        pthread_mutex_unlock(&trylockMutex);
        safe_log(FG_BLUE, "Exiting %s -> Released lock.\n", (char *)arg, -1);
    } else {
        safe_log(FG_RED, "Bypassed %s -> lock occupied! Moving on instead of deadlocking.\n", (char *)arg, -1);
    }
    return NULL;
}

void *datasetReader(void *arg) {
    pthread_rwlock_rdlock(&readerWriterLock);
    safe_log(FG_GREEN, "Reader %s -> Concurrent read data value: %d\n", (char *)arg, sharedDataset);
    pthread_rwlock_unlock(&readerWriterLock);
    return NULL;
}

void *datasetWriter(void *arg) {
    pthread_rwlock_wrlock(&readerWriterLock);
    sharedDataset = 100;
    safe_log(FG_MAGENTA, "Writer %s -> Exclusive write update complete. Set value to: %d\n", (char *)arg, sharedDataset);
    pthread_rwlock_unlock(&readerWriterLock);
    return NULL;
}

int main(void) {
    printf(BOLD UNDERLINE "%c[Advanced Thread Synchronization / Inter-Thread Ops]" RESET, LINEFEED);
    NEWLINE;

    printf(BOLD UNDERLINE "%c[pthread_cond_wait / pthread_cond_signal]" RESET, LINEFEED);
    NEWLINE;
    printf("Signaling Conditions... Syntax: " 
        BOLD "pthread_cond_wait(&cond, &mutex); / pthread_cond_signal(&cond);" RESET);
    NEWLINE;

    pthread_t waitThread, signalThread;
    pthread_create(&waitThread, NULL, waitingWorker, (void*)"waitThread");
    pthread_create(&signalThread, NULL, signalingWorker, (void*)"signalThread");

    pthread_join(waitThread, NULL);
    pthread_join(signalThread, NULL);
    LINEBREAK;

    printf(BOLD UNDERLINE "%c[pthread_mutex_trylock / PTHREAD_MUTEX_RECURSIVE]" RESET, LINEFEED);
    NEWLINE;
    printf("TryLock / Recursive... Syntax: " 
        BOLD "pthread_mutex_trylock(&mutex); / pthread_mutexattr_settype(&attr, TYPE);" RESET);
    NEWLINE;

    pthread_mutexattr_t recursiveMutexAttributes;
    pthread_mutexattr_init(&recursiveMutexAttributes);
    pthread_mutexattr_settype(&recursiveMutexAttributes, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&recursiveMutex, &recursiveMutexAttributes);
    pthread_mutexattr_destroy(&recursiveMutexAttributes);

    pthread_t tryThreadOne, tryThreadTwo;
    pthread_mutex_lock(&trylockMutex); 
    
    pthread_create(&tryThreadOne, NULL, tryLockExample, (void*)"tryThreadOne");
    pthread_create(&tryThreadTwo, NULL, tryLockExample, (void*)"tryThreadTwo");
    
    sleep(1);
    pthread_mutex_unlock(&trylockMutex); 
    
    pthread_join(tryThreadOne, NULL);
    pthread_join(tryThreadTwo, NULL);

    pthread_mutex_lock(&recursiveMutex);
    pthread_mutex_lock(&recursiveMutex); 
    safe_log(FG_YELLOW, "Main Context -> Safely nested locks inside recursive scope without deadlocking.\n", "", -1);
    pthread_mutex_unlock(&recursiveMutex);
    pthread_mutex_unlock(&recursiveMutex);
    LINEBREAK;

    printf(BOLD UNDERLINE "%c[pthread_rwlock_rdlock / pthread_rwlock_wrlock]" RESET, LINEFEED);
    NEWLINE;
    printf("Shared/Exclusive Locking... Syntax: " 
        BOLD "pthread_rwlock_rdlock(&rwlock); / pthread_rwlock_wrlock(&rwlock);" RESET);
    NEWLINE;

    pthread_t readerThreadOne, readerThreadTwo, writerThreadOne;
    pthread_create(&readerThreadOne, NULL, datasetReader, (void*)"ReaderOne");
    pthread_create(&readerThreadTwo, NULL, datasetReader, (void*)"ReaderTwo");
    pthread_create(&writerThreadOne, NULL, datasetWriter, (void*)"WriterOne");

    pthread_join(readerThreadOne, NULL);
    pthread_join(readerThreadTwo, NULL);
    pthread_join(writerThreadOne, NULL);
    LINEBREAK;

    pthread_cond_destroy(&conditionVariable);
    pthread_mutex_destroy(&condMutex);
    pthread_mutex_destroy(&trylockMutex);
    pthread_mutex_destroy(&recursiveMutex);
    pthread_rwlock_destroy(&readerWriterLock);
    pthread_mutex_destroy(&logMutex);

    printf(BOLD FG_GREEN "Advanced Synchronization Complete.\n" RESET);
    return 0;
}

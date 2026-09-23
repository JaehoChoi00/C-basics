#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "../variables/VariableConstants.h"

void *someFunction(void *argumentPointer);
void *threadExitExample(void *argumentPointer);
void *threadCancelExample(void *argumentPointer);
void *detachThreadExample(void *argumentPointer);

pthread_mutex_t loggingMutex = PTHREAD_MUTEX_INITIALIZER;

int main(void) {
    printf(BOLD UNDERLINE "%c[Thread Safety / Multi Threading]" RESET, LINEFEED);
    NEWLINE;

    pthread_t threadOne, threadTwo;

    printf(
        "Creating Thread... Syntax: " 
        BOLD "pthread_create(thread, attribute, routine (function to execute), argument);" RESET
    );
    NEWLINE;

    pthread_create(&threadOne, NULL, someFunction, (void*)"threadOne");
    pthread_create(&threadTwo, NULL, someFunction, (void*)"threadTwo");

    pthread_join(threadOne, NULL);
    pthread_join(threadTwo, NULL);

    printf("Both threads have finished.");
    NEWLINE;

    printf(BOLD UNDERLINE "%c[pthread_exit]" RESET, LINEFEED);
    NEWLINE;

    printf(
        "Exiting Thread Explicitly... Syntax: " 
        BOLD "pthread_exit(retval);" RESET
    );
    NEWLINE;

    pthread_t threadThree;
    pthread_create(&threadThree, NULL, threadExitExample, (void*)"threadThree");
    pthread_join(threadThree, NULL);

    printf(BOLD UNDERLINE "%c[pthread_cancel]" RESET, LINEFEED);
    NEWLINE;

    printf(
        "Canceling a Running Thread... Syntax: " 
        BOLD "pthread_cancel(thread);" RESET
    );
    NEWLINE;

    pthread_t threadFour;
    pthread_create(&threadFour, NULL, threadCancelExample, (void*)"threadFour");
    sleep(5);
    pthread_cancel(threadFour);
    pthread_join(threadFour, NULL);

    printf(BOLD UNDERLINE "%c[pthread_detach]" RESET, LINEFEED);
    NEWLINE;

    printf(
        "Detaching a Thread from the Lifecycle... Syntax: " 
        BOLD "pthread_detach(thread);" RESET
    );
    NEWLINE;

    pthread_t threadFive;
    pthread_create(&threadFive, NULL, detachThreadExample, (void*)"threadFive");
    pthread_detach(threadFive); 

    struct timespec timeSpecification;
    struct tm localTimeStructure;
    if (timespec_get(&timeSpecification, TIME_UTC)) {
        localtime_r(&timeSpecification.tv_sec, &localTimeStructure);
        long milliseconds = timeSpecification.tv_nsec / 1000000;

        pthread_mutex_lock(&loggingMutex);
        printf(FG_BLUE "Current time: [%02d:%02d:%02d.%03ld]" BOLD FG_WHITE " | Main thread continues\n" RESET, 
                localTimeStructure.tm_hour, localTimeStructure.tm_min, localTimeStructure.tm_sec, milliseconds);
        pthread_mutex_unlock(&loggingMutex);
    }
    
    sleep(3); 

    printf(BOLD UNDERLINE "%c[pthread_self]" RESET, LINEFEED);
    NEWLINE;

    printf(
        "Retrieving Current Thread ID... Syntax: " 
        BOLD "pthread_t current_id = pthread_self();" RESET
    );
    NEWLINE;

    pthread_t mainThreadIdentifier = pthread_self();

    if (timespec_get(&timeSpecification, TIME_UTC)) {
        localtime_r(&timeSpecification.tv_sec, &localTimeStructure);
        long milliseconds = timeSpecification.tv_nsec / 1000000;

        pthread_mutex_lock(&loggingMutex);
        printf(FG_YELLOW "Current time: [%02d:%02d:%02d.%03ld]" BOLD FG_WHITE " | Main Thread Unique ID: %lu\n" RESET, 
                localTimeStructure.tm_hour, localTimeStructure.tm_min, localTimeStructure.tm_sec, milliseconds, (unsigned long)mainThreadIdentifier);
        pthread_mutex_unlock(&loggingMutex);
    }
    LINEBREAK;

    pthread_mutex_destroy(&loggingMutex);

    return 0;
}

void *someFunction(void *argumentPointer) {
    struct timespec timeSpecification;
    struct tm localTimeStructure; 

    if (timespec_get(&timeSpecification, TIME_UTC)) {
        clock_t cpuTicks;
        cpuTicks = clock();
        localtime_r(&timeSpecification.tv_sec, &localTimeStructure);
        long milliseconds = timeSpecification.tv_nsec / 1000000;

        pthread_mutex_lock(&loggingMutex);
        printf(FG_GREEN "Current time: [%02d:%02d:%02d.%03ld]" BOLD FG_WHITE " | Running %s\n" RESET, 
            localTimeStructure.tm_hour, localTimeStructure.tm_min, localTimeStructure.tm_sec, milliseconds, (char *)argumentPointer);
        pthread_mutex_unlock(&loggingMutex);

        localtime_r(&timeSpecification.tv_sec, &localTimeStructure);
        milliseconds = timeSpecification.tv_nsec / 1000000;

        pthread_mutex_lock(&loggingMutex);
        printf(FG_GREEN "Current time: [%02d:%02d:%02d.%03ld]" BOLD FG_WHITE " | Exiting %s\n" RESET, 
            localTimeStructure.tm_hour, localTimeStructure.tm_min, localTimeStructure.tm_sec, milliseconds, (char *)argumentPointer);
        pthread_mutex_unlock(&loggingMutex);
        
        cpuTicks = clock() - cpuTicks;

        pthread_mutex_lock(&loggingMutex);
        printf(FG_GREEN BOLD "Thread %s done" RESET " Took cpu ticks %ld ticks (%f seconds)\n" RESET, (char *)argumentPointer, cpuTicks, ((float)cpuTicks) / CLOCKS_PER_SEC);
        pthread_mutex_unlock(&loggingMutex);
    }
    LINEBREAK;
    return NULL;
}

void *threadExitExample(void *argumentPointer) {
    struct timespec timeSpecification;
    struct tm localTimeStructure; 

    if (timespec_get(&timeSpecification, TIME_UTC)) {
        clock_t cpuTicks;
        cpuTicks = clock();
        localtime_r(&timeSpecification.tv_sec, &localTimeStructure);
        long milliseconds = timeSpecification.tv_nsec / 1000000;

        pthread_mutex_lock(&loggingMutex);
        printf(FG_BLUE "Current time: [%02d:%02d:%02d.%03ld]" BOLD FG_WHITE " | Running %s\n" RESET, 
                localTimeStructure.tm_hour, localTimeStructure.tm_min, localTimeStructure.tm_sec, milliseconds, (char *)argumentPointer);
        pthread_mutex_unlock(&loggingMutex);
    }
    LINEBREAK;

    pthread_exit(NULL);
    printf("This will not be executed\n");

    return NULL;
}

void *threadCancelExample(void *argumentPointer) {
    struct timespec timeSpecification;
    struct tm localTimeStructure;
    int loopIncrementation = 1;

    if (timespec_get(&timeSpecification, TIME_UTC)) {
        clock_t cpuTicks;
        cpuTicks = clock();
        localtime_r(&timeSpecification.tv_sec, &localTimeStructure);
        long milliseconds = timeSpecification.tv_nsec / 1000000;

        pthread_mutex_lock(&loggingMutex);
        printf(FG_MAGENTA "Current time: [%02d:%02d:%02d.%03ld]" BOLD FG_WHITE " | Running %s\n" RESET, 
                localTimeStructure.tm_hour, localTimeStructure.tm_min, localTimeStructure.tm_sec, milliseconds, (char *)argumentPointer);
        pthread_mutex_unlock(&loggingMutex);

        while (1) {
            timespec_get(&timeSpecification, TIME_UTC);
            localtime_r(&timeSpecification.tv_sec, &localTimeStructure);
            milliseconds = timeSpecification.tv_nsec / 1000000;

            pthread_mutex_lock(&loggingMutex);
            printf(FG_MAGENTA "Current time: [%02d:%02d:%02d.%03ld]" BOLD FG_WHITE " | Loop Increment %d\n" RESET, 
            localTimeStructure.tm_hour, localTimeStructure.tm_min, localTimeStructure.tm_sec, milliseconds, loopIncrementation++);
            
            if (loopIncrementation == 6) {
                printf(FG_MAGENTA "Current time: [%02d:%02d:%02d.%03ld]" BOLD FG_WHITE " | Exiting %s\n" RESET, 
                localTimeStructure.tm_hour, localTimeStructure.tm_min, localTimeStructure.tm_sec, milliseconds, (char *)argumentPointer);
            }
            pthread_mutex_unlock(&loggingMutex);
            
            sleep(1);
        }

        timespec_get(&timeSpecification, TIME_UTC); 
        localtime_r(&timeSpecification.tv_sec, &localTimeStructure);
        milliseconds = timeSpecification.tv_nsec / 1000000;

        pthread_mutex_lock(&loggingMutex);
        printf(FG_BLUE "Current time: [%02d:%02d:%02d.%03ld]" BOLD FG_WHITE " | Exiting %s\n" RESET, 
                localTimeStructure.tm_hour, localTimeStructure.tm_min, localTimeStructure.tm_sec, milliseconds, (char *)argumentPointer);
        pthread_mutex_unlock(&loggingMutex);
    }
    return NULL;
}

void* detachThreadExample(void *argumentPointer) {
    struct timespec timeSpecification;
    struct tm localTimeStructure;
    if (timespec_get(&timeSpecification, TIME_UTC)) {
        localtime_r(&timeSpecification.tv_sec, &localTimeStructure);
        long milliseconds = timeSpecification.tv_nsec / 1000000;

        pthread_mutex_lock(&loggingMutex);
        printf(FG_CYAN "Current time: [%02d:%02d:%02d.%03ld]" BOLD FG_WHITE " | Running %s\n" RESET, 
                localTimeStructure.tm_hour, localTimeStructure.tm_min, localTimeStructure.tm_sec, milliseconds, (char *)argumentPointer);
        pthread_mutex_unlock(&loggingMutex);

        sleep(2);

        timespec_get(&timeSpecification, TIME_UTC); 
        localtime_r(&timeSpecification.tv_sec, &localTimeStructure);
        milliseconds = timeSpecification.tv_nsec / 1000000;

        pthread_mutex_lock(&loggingMutex);
        printf(FG_CYAN "Current time: [%02d:%02d:%02d.%03ld]" BOLD FG_WHITE " | Exiting %s\n" RESET, 
                localTimeStructure.tm_hour, localTimeStructure.tm_min, localTimeStructure.tm_sec, milliseconds, (char *)argumentPointer);
        pthread_mutex_unlock(&loggingMutex);
    }
    return NULL;
}

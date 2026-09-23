# Extended Thread Safety

[:arrow_left: Return to Main README](../README.md)

[:arrow_left: Move to Thread Safety README](ThreadSafety.md)

> This is a full rundown of the [ThreadSafetyExtended.c](/threadSafety/ThreadSafetyExtended.c) file  
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/threadSafety/   
> gcc ExtendedThreadSafety.c -o ExtendedThreadSafety && ./ExtendedThreadSafety  
> ```
> <br>

## Sections:

> * [`Condition Variables`](#condition-variables)
> * [`Advanced Mutex Lock Variations`](#advanced-mutex-lock-variations)
> * [`Reader-Writer Locks`](#reader-writer-locks)


***Header Files***

```c
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "../variables/VariableConstants.h"
```

---

### [Condition Variables](#sections)

***Creation***

```c
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
```

***C Syntax***

```c
// Syntax: pthread_cond_wait(&cond, &mutex); / pthread_cond_signal(&cond);

pthread_t waitThread, signalThread;
pthread_create(&waitThread, NULL, waitingWorker, (void*)"waitThread");
pthread_create(&signalThread, NULL, signalingWorker, (void*)"signalThread");

pthread_join(waitThread, NULL);
pthread_join(signalThread, NULL);
LINEBREAK;
```

***Output***

```txt
Current time: [00:54:30.217] | Running waitThread -> Waiting for condition predicate...
Current time: [00:54:30.217] | Running signalThread -> Sleeping for 2 seconds before signaling...
Current time: [00:54:32.222] | Exiting signalThread -> Condition signal broadcasted.
Current time: [00:54:32.222] | Exiting waitThread -> Predicate met! Woken up successfully.
```

### [Advanced Mutex Lock Variations](#sections)

***Creation***

```c
void *tryLockExample(void *arg) {
    safe_log(FG_BLUE, "Running %s -> Attempting non-blocking lock...\n", (char *)arg, -1);
    
    if (pthread_mutex_trylock(&trylockMutex) == 0) {
        safe_log(FG_GREEN, "Success %s -> Acquired tryMutex! Working for 1 second...\n", (char *)arg, -1);
        sleep(1);
        pthread_mutex_unlock(&trylockMutex);
        safe_log(FG_BLUE, "Exiting %s -> Released lock.\n", (char *)arg, -1);
    } else {
        safe_log(FG_RED, "Bypassed %s -> lock occupied! Moving on instead of deadlocking.\n", (char *)arg, -1);
    }
    return NULL;
}
```

***C Syntax***

```c
// Syntax: pthread_mutex_trylock(&mutex); / pthread_mutexattr_settype(&attr, TYPE);

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
```

***Output***

```txt
Current time: [00:54:32.223] | Running tryThreadOne -> Attempting non-blocking lock...
Current time: [00:54:32.223] | Bypassed tryThreadOne -> lock occupied! Moving on instead of deadlocking.
Current time: [00:54:32.223] | Running tryThreadTwo -> Attempting non-blocking lock...
Current time: [00:54:32.223] | Bypassed tryThreadTwo -> lock occupied! Moving on instead of deadlocking.
Current time: [00:54:33.223] | Main Context -> Safely nested locks inside recursive scope without deadlocking.
```

### [Reader-Writer Locks](#sections)

***Creation***

```c
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
```

***C Syntax***

```c
// Syntax: pthread_rwlock_rdlock(&rwlock); / pthread_rwlock_wrlock(&rwlock);

pthread_t readerThreadOne, readerThreadTwo, writerThreadOne;
pthread_create(&readerThreadOne, NULL, datasetReader, (void*)"ReaderOne");
pthread_create(&readerThreadTwo, NULL, datasetReader, (void*)"ReaderTwo");
pthread_create(&writerThreadOne, NULL, datasetWriter, (void*)"WriterOne");

pthread_join(readerThreadOne, NULL);
pthread_join(readerThreadTwo, NULL);
pthread_join(writerThreadOne, NULL);
LINEBREAK;
```

***Output***

```txt
Current time: [00:54:33.223] | Reader ReaderOne -> Concurrent read data value: 64
Current time: [00:54:33.224] | Reader ReaderTwo -> Concurrent read data value: 64
Current time: [00:54:33.224] | Writer WriterOne -> Exclusive write update complete. Set value to: 100
```

[:arrow_up: Return to Top](#extended-thread-safety)
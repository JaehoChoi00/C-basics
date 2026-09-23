# Thread Safety

[:arrow_left: Return to Main README](../README.md)

[:arrow_right: Move to Extended Thread Safety README](ThreadSafetyExtended.md)

> This is a full rundown of the [ThreadSafety.c](/threadSafety/ThreadSafety.c) file  
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/threadSafety/   
> gcc ThreadSafety.c -o ThreadSafety && ./ThreadSafety  
> ```
> <br>

<br>

[Learning Resource](https://geeksforgeeks.org)

## Sections:

> * [`Thread Creation and Joining`](#thread-creation-and-joining)
> * [`Explicit Thread Exit`](#explicit-thread-exit)
> * [`Thread Cancellation`](#thread-cancellation)
> * [`Thread Detaching`](#thread-detaching)
> * [`Self Identification`](#self-identification)

---

***Header Files***

```c
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "../variables/VariableConstants.h"
```

### [Thread Creation and Joining](#sections)

***Creation***

```c
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
```

***C Syntax***

```c
// Syntax: pthread_create(thread, attribute, routine (function to execute), argument);

pthread_t threadOne, threadTwo;

pthread_create(&threadOne, NULL, someFunction, (void*)"threadOne");
pthread_create(&threadTwo, NULL, someFunction, (void*)"threadTwo");

pthread_join(threadOne, NULL);
pthread_join(threadTwo, NULL);

printf("Both threads have finished.");
NEWLINE;
```

***Output***

```txt
Current time: [00:37:24.446] | Running threadOne
Current time: [00:37:24.446] | Exiting threadOne
Thread threadOne done Took cpu ticks 317 ticks (0.000317 seconds)

--------------------------------
Current time: [00:37:24.446] | Running threadTwo
Current time: [00:37:24.446] | Exiting threadTwo
Thread threadTwo done Took cpu ticks 335 ticks (0.000335 seconds)

--------------------------------
Both threads have finished.
```

### [Explicit Thread Exit](#sections)

***Creation***

```c
// Syntax: pthread_exit(retval);

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
```

***C Syntax***

```c
pthread_t threadThree;
pthread_create(&threadThree, NULL, threadExitExample, (void*)"threadThree");
pthread_join(threadThree, NULL);
```

***Output***

```txt
Current time: [00:37:24.446] | Running threadThree
```

### [Thread Cancellation](#sections)

***Creation***

```c
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
    }
    return NULL;
}
```

***C Syntax***

```c
// Syntax: pthread_cancel(thread);

pthread_t threadFour;
pthread_create(&threadFour, NULL, threadCancelExample, (void*)"threadFour");
sleep(5);
pthread_cancel(threadFour);
pthread_join(threadFour, NULL);
```

***Output***

```txt
Current time: [00:40:23.400] | Running threadFour
Current time: [00:40:23.401] | Loop Increment 1
Current time: [00:40:24.402] | Loop Increment 2
Current time: [00:40:25.403] | Loop Increment 3
Current time: [00:40:26.404] | Loop Increment 4
Current time: [00:40:27.405] | Loop Increment 5
Current time: [00:40:27.405] | Exiting threadFour
```

### [Thread Detaching](#sections)

***Creation***

```c
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
```

***C Syntax***

```c
// Syntax: pthread_detach(thread);

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
```

***Output***

```txt
Main thread continues
Current time: [00:40:28.911] | Running threadFive
Current time: [00:40:30.912] | Exiting threadFive
```

### [Self Identification](#sections)

***C Syntax***

```c
// Syntax: pthread_t current_id = pthread_self();

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
```

***Output***

```txt
Current time: [00:37:32.448] | Main Thread Unique ID: 8324358336
```

[:arrow_up: Return to Top](#thread-safety)
# Time

[:arrow_left: Return to Main README](../README.md)

> This is a full rundown of the [Time.c](/time/Time.c) file  
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/time/   
> gcc Time.c -o Time && ./Time  
> ```
> <br>

## Sections:

> * [`Includes`](#includes)
> * [`Standard Date and Time Strings`](#standard-date-and-time-strings)
> * [`Measuring CPU Execution Time`](#measuring-cpu-execution-time)
> * [`Custom Time Formatting`](#custom-time-formatting)
> * [`Millisecond Precision Formatting`](#millisecond-precision-formatting)

---

### [Includes](#sections)

```c
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "../variables/VariableConstants.h"
```

### [Standard Date and Time Strings](#sections)

***C Syntax***

```c
time_t currentTime;
time_t sameThing;
sameThing = time(NULL);
time(&currentTime);

time(&currentTime);
printf(BOLD FG_BLUE "Current Date and Time: %s" RESET, ctime(&currentTime));
NEWLINE;

struct tm *localTime;
time(&currentTime);
localTime = localtime(&currentTime);
printf(BOLD FG_CYAN "Current Local Date and Time: %s" RESET, asctime(localTime));
NEWLINE;

time(&currentTime);
localTime = gmtime(&currentTime);
printf(BOLD FG_GREEN "Current Local Date and Time in UTC: %s" RESET, asctime(localTime));
LINEBREAK;
```

***Output***

```txt
Current Date and Time: Sun Sep 20 11:21:42 2026

Current Local Date and Time: Sun Sep 20 11:21:42 2026

Current Local Date and Time in UTC: Sun Sep 20 02:21:42 2026
```

---

### [Measuring CPU Execution Time](#sections)

***C Syntax:*** *Within int main()*

```c
clock_t cpuTicks;
cpuTicks = clock();
multipleDownloads();
cpuTicks = clock() - cpuTicks;
printf(BOLD FG_GREEN "Number of cpu ticks %ld ticks (%f seconds)." RESET, cpuTicks, ((float)cpuTicks) / CLOCKS_PER_SEC);
LINEBREAK;
```

***C Syntax:*** *Supporting Functions*

```c
void printProgressBar(const char *filename, int percent, int spinner_idx) {
    CLEAR_ROW;
    printf(BOLD FG_WHITE "%s [", filename);

    for (int j = 0; j < percent / 5; j++) { printf("#"); }
    for (int j = percent / 5; j < 20; j++) { printf("."); }

    if (percent >= 100) { printf("] %d%% " FG_GREEN "✓" RESET, percent); } 
    else { printf("] %d%% %c", percent, SPINNER[spinner_idx % 4]); }
}

void multipleDownloads() {
    int file1 = 0, file2 = 0, file3 = 0;
    int tick = 0;

    printf(BOLD FG_GREEN "\nInitializing Simultaneous Streams...\n" RESET);

    printf("\n\n\n");

    while (file1 < 100 || file2 < 100 || file3 < 100) {
        MOVE_UP(3);

        printProgressBar("Downloading file 1", file1, tick);
        printf("\n");

        printProgressBar("Downloading file 2", file2, tick);
        printf("\n");

        printProgressBar("Downloading file 3", file3, tick);
        printf("\n");

        fflush(stdout);

        if (file1 < 100) file1 += 8;
        if (file2 < 100) file2 += 4;
        if (file3 < 100) file3 += 5;

        if (file1 > 100) file1 = 100;
        if (file2 > 100) file2 = 100;
        if (file3 > 100) file3 = 100;

        tick++;
        usleep(80000); 
    }
    MOVE_UP(3);
    printProgressBar("Downloading file 1", file1, tick);  printf("\n");
    printProgressBar("Downloading file 2", file2, tick);  printf("\n");
    printProgressBar("Downloading file 3", file3, tick);
    fflush(stdout);

    LINEBREAK;
    printf(BOLD FG_GREEN "All parallel processes successfully downloaded!\n" RESET);
}
```

***Output***

```txt
Initializing Simultaneous Streams...
Downloading file 1 [####################] 100% ✓
Downloading file 2 [####################] 100% ✓
Downloading file 3 [####################] 100% ✓
--------------------------------
All parallel processes successfully downloaded!
Number of cpu ticks 320 ticks (0.000320 seconds).
```

---

### [Custom Time Formatting](#sections)

***C Syntax***

```c
char buffer[80];
time(&currentTime);
localTime = localtime(&currentTime);
strftime(buffer, 80, BOLD FG_RED "Time in hour:minute Format is: %I:%M %p." RESET, localTime);
puts(buffer);
NEWLINE;
```

***Output***

```txt
Time in hour:minute Format is: 11:21 AM.
```

---

### [Millisecond Precision Formatting](#sections)

***C Syntax***

```c
struct timespec timeSpec;

if (timespec_get(&timeSpec, TIME_UTC)) {
    localTime = localtime(&timeSpec.tv_sec);
    long milliseconds = timeSpec.tv_nsec / 1000000;
    printf(BOLD FG_COLOR(50) "Current time (HH:MM:SS.mmm) | %02d:%02d:%02d.%03ld" RESET,
        localTime->tm_hour,
        localTime->tm_min,
        localTime->tm_sec,
        milliseconds);
}
NEWLINE;
```

***Output***

```txt
Current time (HH:MM:SS.mmm): 11:21:42.582
```

[:arrow_up: Return to Top](#time)
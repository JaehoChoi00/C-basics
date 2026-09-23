#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "../variables/VariableConstants.h"

void multipleDownloads();

#define MOVE_UP(x) printf("%c[%dA", ESCAPE, x)
#define CLEAR_ROW printf("%s", CLEAR_LINE)

int main()
{
    time_t startTime, endTime;
    startTime = time(NULL);

    printf(BOLD UNDERLINE "%c[Time]" RESET, LINEFEED);
    NEWLINE;

    time_t currentTime;
    time_t sameThing;
    sameThing = time(NULL);
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

    clock_t cpuTicks;
    cpuTicks = clock();
    multipleDownloads();
    cpuTicks = clock() - cpuTicks;
    printf(BOLD FG_GREEN "Number of cpu ticks %ld ticks (%f seconds)." RESET, cpuTicks, ((float)cpuTicks) / CLOCKS_PER_SEC);
    LINEBREAK;

    char buffer[80];
    time(&currentTime);
    localTime = localtime(&currentTime);
    strftime(buffer, 80, BOLD FG_RED "Time in hour::minute Format is: %I:%M %p." RESET, localTime);
    puts(buffer);
    NEWLINE;

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

    endTime = time(NULL);
    printf(BOLD FG_YELLOW "Time taken for this whole program to finish: %.2f seconds" RESET, difftime(endTime, startTime));
    NEWLINE;
    return 0;
}

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
# Header Files

[:arrow_left: Return to Main README](../README.md)

> This is a full rundown of these files:
> * [`HeaderFiles.c`](/headers/HeaderFiles.c) 
> * [`HeaderFiles.h`](/headers/HeaderFiles.h) 
> * [`HeaderExperimentation.c`](/headers/HeaderExperimentation.c) 
> * [`HeaderExperimentation.h`](/headers/HeaderExperimentation.h) 
> * [`main.c`](/headers/main.c) 
>
> ---
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/headers/   
> gcc main.c HeaderFiles.c HeaderExperimentation.c -o HeaderFiles && ./HeaderFiles  
>
> or 
> 
> gcc *.c -o HeaderFiles && ./HeaderFiles  
> ``` 
> 
> <br>

## Sections:

> * [`The .h Side`](#the-h-side)
> * [`The .c Side`](#the-c-side)
> * [`The main.c`](#the-mainc)
> * [`The Result`](#the-result)
> * [`Personal Experiments`](#personal-experiments)
>     * [`Simple Calculator`](#simple-calculator)
>     * [`The Variable Constants`](#the-variable-constants)
> * [`Reference`](#reference)


---

## [The <code>.h</code> Side](#sections)

```h
#ifndef HEADERFILES_H // Checks: Has this specific file been read yet?
#define HEADERFILES_H // Marks this file as read so it won't be duplicated

// Function declaration: Tells the compiler the name and type of the function
void someFunctionInHeaderFile(void);

#endif // Ends the guard block; code below this would always be read

```

## [The <code>.c</code> Side](#sections)

```c
#include <stdio.h>
#include "HeaderFiles.h" // Copies declarations so main knows the functions exist

void someFunctionInHeaderFile(void) {
    printf("This is a function definition\n");
}
```

## [The <code>main.c</code>](#sections)

```c
#include <stdio.h>
#include "HeaderFiles.h" // Copies declarations so main knows the functions exist

int main(void) {
    
    someFunctionInHeaderFile();

    return 0;
}

// gcc main.c HeaderFiles.c HeaderExperimentation.c -o header_files

// Quickest way is gcc *.c -o header_files
/*
    This compiles every .c file in the folder you are in.
*/

```

## [The Result](#sections)

***Bash Terminal Compiling***

```bash
@User C basics % cd headers 
@User headers % gcc main.c HeaderFiles.c -o header_files
@User headers % ./header_files 
```

***Output***

```out
This is a function definition
```


# [Personal Experiments](#sections)

> This is where I will come back time to time to explore on creating libraries.
>
> **Currently**, I am learning cmake to eventually make everything expandable for a bigger project and experiments.

## [Simple Calculator](#sections)

> A short math library for **adding, subtracting, multiplying, dividing, and getting the modulus** of two integers `a` and `b`.

***header file***

```h
#ifndef HEADEREXPERIMENTATION_H 
#define HEADEREXPERIMENTATION_H

// simple add function
int add(int, int);

// simple sub function
int sub(int, int);

// simple mul function
int mul(int, int);

// simple div function
int div(int, int);

// simple mod function
int mod(int, int);

#endif
```

***c file***

```c
#include "HeaderExperimentation.h"

// Simple integer add function
int add(int a, int b) {
    return a + b;
}

// Simple integer sub function
int sub(int a, int b) {
    return a - b;
}

// Simple integer mul function
int mul(int a, int b) {
    return a * b;
}

// Simple integer div function
int div(int a, int b) {
    return a / b;
}

// Simple integer mod function
int mod(int a, int b) {
    return a % b;
}
```

### Trying it out:

***main.c***

```c
#include <stdio.h>
#include "HeaderFiles.h" // Copies declarations so main knows the functions exist
#include "HeaderExperimentation.h"

int main(void) {
    
    someFunctionInHeaderFile(); 

    printf("1 + 1 = %d\n", add(1, 1));

    printf("1 - 1 = %d\n", sub(1, 1));

    printf("2 * 3 = %d\n", mul(2, 3));

    printf("2 / 3 = %d\n", div(2, 3));

    printf("2 %% 3 = %d\n", mod(2, 3));

    return 0;
}
```

***Output***

```out
This is a function definition
1 + 1 = 2
1 - 1 = 0
2 * 3 = 6
2 / 3 = 0
2 % 3 = 2
```

## [The Variable Constants](#sections)

> The variable constants identified in the [Variables](/variables/Variables.md) Section.

```h
#ifndef VARIABLECONSTANTS_H
#define VARIABLECONSTANTS_H

// --- ANSI ESCAPE STYLE MACROS ---
#define RESET          "\033[0m"
#define BOLD           "\033[1m"
#define DIM            "\033[2m"
#define UNDERLINE      "\033[4m"
#define BLINK          "\033[5m"
#define INVERT         "\033[7m"
#define STRIKETHROUGH  "\033[9m"

// --- FOREGROUND COLORS ---
#define FG_BLACK       "\033[30m"
#define FG_RED         "\033[31m"
#define FG_GREEN       "\033[32m"
#define FG_YELLOW      "\033[33m"
#define FG_BLUE        "\033[34m"
#define FG_MAGENTA     "\033[35m"
#define FG_CYAN        "\033[36m"
#define FG_WHITE       "\033[37m"

// --- BACKGROUND COLORS ---
#define BG_BLACK       "\033[40m"
#define BG_RED         "\033[41m"
#define BG_GREEN       "\033[42m"
#define BG_YELLOW      "\033[43m"
#define BG_BLUE        "\033[44m"
#define BG_MAGENTA     "\033[45m"
#define BG_CYAN        "\033[46m"
#define BG_WHITE       "\033[47m"

// --- ADVANCED LAYOUT UTILITIES ---
#define CLEAR_LINE     "\033[2K\r"

// --- SCREEN & KEYBOARD CONTROLS ---
#define endOfString = 0          // ASCII code for NUL / NULL pointer termination
#define bell = 7                 // ASCII code to play system audio alert sound
#define backSpace = 8            // ASCII code to move terminal cursor backward one space
#define horizontalTab = 9        // ASCII code to shift text by a tab key column amount
#define lineFeed = 10            // ASCII code for \n to drop cursor down to next line
#define carriageReturn = 13      // ASCII code for \r to return cursor to start of current line
#define escape = 27              // ASCII code for ESC to start terminal formatting commands

// --- DATA TRANSMISSIONS ---
#define startOfHeading = 1       // Marks the beginning of metadata (like file name or address)
#define startOfText = 2          // Signals that the actual body of the message is starting
#define endOfText = 3            // Signals that the body of the message is finished
#define endOfTransmission = 4    // Closes the raw active data transmission stream
#define enquiry = 5              // Asks the remote device "Are you there? Send your status."
#define acknowledge = 6          // The receiving device replies "Yes, I am here and ready."
#define negativeAcknowledge = 21 // The receiver replies "Error! Last data packet corrupted, resend."
#define synchronousIdle = 22     // Sent periodically to keep two communications devices in sync
#define endOfTransmitBlock = 23  // Marks the end of a single chunk when dividing massive files

// --- PHYSICAL MACHINE CONTROL ---
#define verticalTab = 11         // Jumped the paper roller downward to a pre-set row
#define formFeed = 12            // Ejected the current physical piece of paper out for a fresh page
#define shiftOut = 14            // Switched mechanical printer ribbons to alternate color/font (e.g., Red)
#define shiftIn = 15             // Switched printer ribbon back to the default black/standard font
#define dataLinkEscape = 16      // Changes meaning of the very next character to a raw hardware command
#define deviceControl1 = 17      // Custom hardware switch. Universally used as "XON" to resume reader
#define deviceControl2 = 18      // Custom hardware switch for secondary attached device operations
#define deviceControl3 = 19      // Custom hardware switch. Universally used as "XOFF" to pause reader
#define deviceControl4 = 20      // Custom hardware switch for secondary attached device operations
#define cancel = 24              // Tells mechanical printer to ignore everything typed on current line
#define endOfMedium = 25         // Triggered alarm indicating machine was out of paper tape or ink ribbon
#define substitute = 26          // Replaced a character that couldn't be printed due to data corruption

// --- ANCIENT DATABASE SEPARATORS ---
#define fileSeparator = 28       // Acted like a modern folder boundary to separate files in a stream
#define groupSeparator = 29      // Acted like a sub-folder boundary to separate records within a file
#define recordSeparator = 30     // Acted like a spreadsheet row boundary to separate individual records
#define unitSeparator = 31       // Acted like a spreadsheet column boundary to separate fields in a record
#define deleteChar = 127         // ASCII for DEL (1111111) used to physically punch holes over tape mistakes

// --- UTILITIES ---
#define spinner ((char[]){'|', '/', '-', '\\'})  // Characters for a quick downloading/loading animation loop

#endif
```

## [Reference](#sections)

> * [Common C keywords](https://www.w3schools.com/c/c_ref_reference.php)

# Variables

[:arrow_left: Return to Main README](../README.md)

> This is a full rundown of the [Variable.c](/variables/Variables.c) file  
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/variables/   
> gcc Variables.c -o Variables && ./Variables  
> ```

## Sections:

> * [`Predefined`](#predefined)
>     * [`ASCII STYLE`](#ascii-style)
>     * [`Invisible Characters`](#invisible-characters)
> * [`The Unsigned`](#the-unsigned)
> * [`The Character`](#the-character)
>     * [`Visible Characters`](#visible-characters)
>     * [`%c Specifier`](#c-specifier)
>     * [`%d Specifier`](#d-specifier)
>     * [`Unicode Characters`](#unicode-character)
> * [`The Integer`](#the-integer)
>     * [`Specifier %d, %i`](#specifier-d-i)
>     * [`Specifier %u`](#specifier-u)
>     * [`Specifier Specifier %o Octal`](#specifier-o-octal)
>     * [`Specifier %x Hexadecimal`](#specifier-x-hexadecimal)
> * [`Shorts`](#shorts)
>     * [`Specifier %hd`](#specifier-hd)
>     * [`Specifier %hu`](#specifier-hu)
> * [`Long`](#long)
> * [`The Float`](#the-float)
> * [`The Double`](#the-double)
> * [`The String`](#the-string)
> * [`The Boolean`](#the-boolean)
> * [`Pointers & Address`](#pointers-&-address)
> * [`Others`](#others)

## [Predefined](#sections)

> These are my hand crafted #defines that I have made to be used for terminal and string manipulations. 
> After learning about header files, I have made a separate header file as well with these defined variables.

### :arrow_right: [To the Variable Constants Header in Experimentations](/headers/Headers.md)

### ASCII STYLE

```c
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
```

> ### Explanation

```c
// Use case for special formats after 27.
printf("%c[32m", escape); // 32 = green and m = menu code.
printf("\nGreen text\n");
printf("%c[0m", escape); // 0 resets the format.
```

### INVISIBLE CHARACTERS

```c
    // These invisible ASCII codes are for manipulating the terminal windows.

    // Screen & Keyboard Controls.
    char endOfString = 0; // ASCII code for NUL - NULL
    char bell = 7; // ASCII code to play system alert sound
    char backSpace = 8; // ASCII code to move terminal cursor backward one space.
    char horizontalTab = 9; // ASCII code to shift text by a tab key column amount.
    char lineFeed = 10;
    char carriageReturn = 13; // ASCII code for \r return to start of current line.
    char escape = 27; // ASCII code for ESC Escape that tells the system that the following characters are special formatting commands (like text color).

    // Data transmissions.
    char startOfHeading = 1; // Marks the beginning of meta data [file name or address]
    char startOfText = 2; // Signals that the actual body of the message is starting
    char endOfText = 3; // Signals that the body of the message is finished.
    char endOfTransmission = 4; // Closes data stream.
    char enquiry = 5; // Asks the computer "Are you there? Send your status."
    char acknowledge = 6; // The receiving computer replies "Yes, I am here and ready."
    char negativeAcknowledge = 21; // The receiving computer replies "Error! The last data packet was corrupted, send again."
    char synchronousIdle = 22; // Sent periodically to keep two communication devices in perfect sync.
    char endOfTransmitBlock = 23; // Marks the end of a single chunk of data when dividing a massive file.

    // Physical machine control. For Teletypewriters
    char verticalTab = 11;       // Jumped the paper roller downward to a pre-set row (like skip to invoice totals box).
    char formFeed = 12;          // Ejected the entire current physical piece of paper out of the printer for a fresh page.
    char shiftOut = 14;          // Switched the mechanical printing ribbons to an alternate color or font set (e.g., red ink or bold).
    char shiftIn = 15;           // Switched the printing ribbon back to the default black/standard text font.
    char dataLinkEscape = 16;    // Changes the meaning of the very next transmission character to a raw hardware command.
    char deviceControl1 = 17;    // Custom hardware switch. Universally used as "XON" to resume a paused paper tape reader.
    char deviceControl2 = 18;    // Custom hardware switch for secondary attached device operations.
    char deviceControl3 = 19;    // Custom hardware switch. Universally used as "XOFF" to pause a paper tape reader machine.
    char deviceControl4 = 20;    // Custom hardware switch for secondary attached device operations.
    char cancel = 24;            // Tells a mechanical printer, "Ignore everything typed on this current line, it was a mistake."
    char endOfMedium = 25;       // Triggered an alarm indicating the machine was entirely out of paper tape or printer ink ribbon.
    char substitute = 26;        // Used to replace a character that the machine physically could not read or print due to data corruption.

    // Ancient Database Separators
    char fileSeparator = 28;     // Acted like a modern "Folder" boundary to separate different data files in a raw stream.
    char groupSeparator = 29;    // Acted like a sub-folder boundary to separate collections of records within a file.
    char recordSeparator = 30;   // Acted like a spreadsheet row boundary to separate individual data records.
    char unitSeparator = 31;     // Acted like a spreadsheet column boundary to separate individual fields within a record.
    
    // The Hardware Eraser
    char deleteChar = 127;       // ASCII code for DEL. Written in binary as 1111111 to physically punch holes over tape mistakes.
```

## [The Unsigned](#sections)

> Standard char uses 1 byte (8 bits) of memory. The difference between signed and unsigned is how the computer interprets the very first bit (the most significant bit).
>
> ```txt
> SIGNED CHAR (The Default)
> - Uses the first bit as a +/- sign flag.
> - Range: -128 to 127
> - Binary 11111111 represents -1.
>
> UNSIGNED CHAR
> - Disables the sign flag. All 8 bits are used purely for positive numbers.
> - Range: 0 to 255
> - Binary 11111111 represents 255.
> ```

## [The Character](#sections)

### [Visible Characters](#sections)

> Wherever the (`BOLD` `UNDERLINE`, `RESET`, ... ) It is utilizing the #defined variables

```c
// Visible characters
printf(BOLD UNDERLINE "\n[Characters]\n\n" RESET); 
char character = 'a'; // Signed and counts from -128 to 127 for bits

char minVisibleCharacter = 32;
printf("[%c]\n", minVisibleCharacter); // Results in printing the [ ] space character
char maxVisibleCharacter = 126;
printf("%c\n", maxVisibleCharacter); // Results in printing the [~] space character
```

***Output***

```out
[Characters]

[ ]
~
```

### [%c Specifier](#sections)

```c
// Specifier %c
printf("%c\n", character);
character++;
printf("%c\n", character); // Results in printing 'b'
character -= 2;
printf("%c\n", character); // Results in printing [']
character += 1; // Resets to 'a'
```

***Output***

```out
a
b
`
```


### [%d Specifier](#sections)

```c
// Specifier %d
printf("%d\n", character); // Result in printing 97. the ASCII integer for 'a'.
character++;
printf("%d\n", character); // Results in printing 98
character -= 2;
printf("%d\n", character); // Results in printing 96
character += 1; // Resets to 'a'

unsigned char rgb = 255; // For RGB, raw binary file data, raw data
unsigned char encryption_key[4] = { 0xDE, 0xAD, 0xBE, 0xEF };
```

***Output***

```out
97
98
96
```

## [Unicode Character](#sections)

***Include***

```c
#include <wchar.h> // For wide character support. Unicode
#include <locale.h> // Required to tell the terminal to support Unicode
```

> ***FUN FACT:***
>
> The `l` in `%lc` stands for **length modifier**.  
> The `c` stanrds for **Character**  
> Altogehter meaning **Wide Character**.
>
> A single [character](#the-character) expects 1 byte.  
> A single `lc` expects 2 or 4 bytes.
>
> The `s` in `%ls` stands for **String**. 
> 

```c
//Unicode Characters 
setlocale(LC_ALL, ""); // Tells terminal to interpret outputs as UTF-8 Unicode

wchar_t rocketEmoji = L'🚀';
wchar_t wide_str_hello_world[] = L"你好，世界 🌍. 세상아, 안녕🌍"; 

// Specifier %lc
printf("\nRocket: %lc\n", rocketEmoji);

// Specifier %ls
printf("\nOther languages: %ls\n", wide_str_hello_world);
```
5
***Output***

```out
Rocket: 🚀

Other languages: 你好，世界 🌍. 세상아, 안녕🌍
```

## [The Integer](#sections)

***Include***

```c
#include <stdint.h>
```

```c
printf(BOLD UNDERLINE "\n[Integers]\n\n" RESET);
int integer = 2147483647; // Signed 2^32 halved to share between negative and positive
unsigned int unsignedInteger = 4294967295; // Unsigned 2^32 full from 0 to 2^32.
```

### [Specifier %d, %i](#sections)

```c
// Specifier %d, %i
printf("Signed integers:\n");
printf("%d\n", integer);
printf("%i\n", integer); // Prints the variable as a signed base-10 integer (identical to %d here)
integer++;
printf("%d\n", integer); // Will output -2147483648. As the sign has been inverted.
integer--;
```

***Output***

```out
Signed integers:
2147483647
2147483647
-2147483648
```

### [Specifier %u](#sections)

```c
// Specifier %u
printf("\nUnsigned integers:\n");
printf("%u\n", unsignedInteger);
unsignedInteger++;
printf("%u\n", unsignedInteger);
unsignedInteger--;
```

***Output***

```out
Unsigned integers:
4294967295
0
```

### [Specifier %o Octal](#sections)

```c
// Specifier %o Octal
printf("\nOctal integers:\n");
printf("%d -> %o\n", integer, integer); 
```

***Output***

```out
Octal integers:
2147483647 -> 17777777777
```

### [Specifier %x Hexadecimal](#sections)

```c
// Specifier %x Hexadecimal
printf("\nHexadecimal integers:\n");
printf("%d -> %x\n", integer, integer); 
```

***Output***

```out
Hexadecimal integers:
2147483647 -> 7fffffff
```

## [Shorts](#sections)

### [Specifier %hd](#sections)

> ***FUN FACT:***  
> 
> The `h` in `%hd` stands for **half**. Where a **Short** is exactly half the size of a standard **integer**.
>
> The `d` here means decimal.

```c
// Specifier %hd
short shortNum = 32767; // Signed
printf("%hd\n", shortNum);

```

***Output***

```out
32767
```

### [Specifier %hu](#sections)

> The `u` here means unsigned.

```c
// Specifier %hu
unsigned short unsignedShortNum = 65535; // Unsigned
printf("%hu\n", unsignedShortNum);
```

***Output***

```out
65535
```


## [Long](#sections)

> ***FUN FACT:***  
> 
> The `l` in `%ld`, `%li`, `%lli`, `%lld`, and `%llu` all stand for **Long**.  
> 
> The `d` here means decimal.
> The `i` here means integer.
> The `u` here means unsigned.
>
> A **single** `l` = 32-Bits
> A **double** `ll` = 64-Bits
>
> The numbers above may seem like impossible numbers to comprehend.
> But these are some examples on would consider using them:
> 1. **High-Precision Time** 
>     * Tracking time in milliseconds or microseconds (standard 32-bit time breaks in the year 2038)
> 2. **Global Finance**
>     * Calculating money down to the fraction of a cent for millions of international bank transactions.
> 3. **Network Traffic**
>     * Counting the trillions of data packets passing through internet routers and servers.
> 4. **Large File Sizes**
>     * You need `l` to at least represent Gigabytes of data. That means for Terabytes of data, we need `ll`.

```c
// Specifier %ld, %li
long longNum = 9223372036854775807L; // Signed and dependent on OS
printf("%ld\n", longNum);
printf("%li\n\n", longNum);

// Specifier %lli, %lld
long long tooLongNum = 9223372036854775807; // Signed and same on all OS
printf("%lli\n", tooLongNum);
printf("%lld\n\n", tooLongNum);

// Specifier %llu
unsigned long long tooMuchNum = 18446744073709551615ULL; 
printf("%llu\n", tooMuchNum);
```

***Output***

```out
[Long]

9223372036854775807
9223372036854775807

9223372036854775807
9223372036854775807

18446744073709551615
```

## [The Float](#sections)

***Include***

```c
#include <float.h>
```

```c
float floatSize = FLT_MAX; // 2^128

// Specifier %f, %e, %E
printf("Maximum float number: %f\n", floatSize); 
printf("Maximum float number: %e\n", floatSize); // Using the exponentional notation
printf("Maximum float number: %E\n", floatSize); // Using the exponentional notation

float floatExample = 3.1415926;
printf("pi = %.2f\n",floatExample); // .2 = 2 decimal place.
```

***Output***

```out
Maximum float number: 340282346638528859811704183484516925440.000000
Maximum float number: 3.402823e+38
Maximum float number: 3.402823E+38
pi = 3.14
```


## [The Double](#sections)

```c
    printf(BOLD UNDERLINE "\n[Double]\n\n" RESET);

    // Specifier %lf
    double doubleSize = DBL_MAX;
    printf("Maximum double number: %lf\n", doubleSize);
```

***Output***

```out
[Double]

Maximum double number: 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000

```

## [The String](#sections)

```c
printf(BOLD UNDERLINE "\n[Strings]\n\n" RESET);
char string[] = "Hello World!";

// Specifier %s
printf("%s\n", string); 
string[0] = 'Y';
printf("%s\n", string);
string[0]-=17;
printf("%s\n", string);
printf("[%c]\n", string[12]); // This is the null terminator
```

***Output***

```out
[Strings]

Hello World!
Yello World!
Hello World!
[]
```

## [The Boolean](#sections)

***Include***

```c
#include <stdbool.h>
```

```c
bool yesOrNo = true; // 1 or 0. It doesn't matter if the value is assigned to be greater than 1. It will still be 1
bool fuse = false; // If we link the fuse variable to any circuit or logic. It becomes a very simple and elegant single use detector.

printf("\nYes or No = %d`\n", yesOrNo);
```

***Output***

```out
Yes or No = 1% 
```


## [Pointers & Address](#sections)

```c
printf(BOLD UNDERLINE "\n[Pointers & Address]\n\n" RESET);

// Specifier %p
printf("Memory Address of [string]: %p\n", &string);
```

***Output***

```out
[Pointers & Address]

Memory Address of [string]: 0x16cf4a8b0
```

## [Others](#sections)

```c
int foo; // foo is just a generic statement. Mostly to mean absolutely nothing but the variable it represents.
int bar; // This too.
int bax; // And this.
int quz; // This four.

int alice; // for cyber security. The person trying to send a message
int bob; // This too. The person trying to receive.
int eve; // And this. The person trying to hack.
```
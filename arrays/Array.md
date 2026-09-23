# Array

[:arrow_left: Return to Main README](../README.md)

> This is a full rundown of the [`Array.c`](/arrays/Arrays.c) file  
>
> ---
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/arrays/   
> gcc Array.c -o Array && ./Array  
> ``` 
> 
> <br>

## Sections

> * [`String`](#string)
>   * [`Basic Character & String Printing`](#basic-character--string-printing)
>   * [`String Length & Size Analysis`](#string-length--size-analysis)
>   * [`Character Iteration & Null Terminator`](#character-iteration--null-terminator)
> * [`Integer`](#integer)
>   * [`1D Integer Array Memory & Sizing`](#1d-integer-array-memory--sizing)
> * [`Multi-Dimensional Arrays`](#multi-dimensional-arrays)
>   * [`2D Integer Array Sizing & Traversal`](#2d-integer-array-sizing--traversal)
>   * [`2D String Pointer Array Traversal`](#2d-string-pointer-array-traversal)

---

### [String](#sections)

> * [`Basic Character & String Printing`](#basic-character--string-printing)
> * [`String Length & Size Analysis`](#string-length--size-analysis)
> * [`Character Iteration & Null Terminator`](#character-iteration--null-terminator)

#### [Basic Character & String Printing](#string)

***Syntax C***

```c
char character = 'C';
char string[] = "This is a string. Array of Characters";

printf(BOLD FG_COLOR(190) "%c%c%c" RESET, LINEFEED, character, LINEFEED);
printf(BOLD FG_GREEN "%c%s%c" RESET, LINEFEED, string, LINEFEED);

```

***Output***

```txt
C

This is a string. Array of Characters

```

---

#### [String Length & Size Analysis](#string)

***Syntax C***

```c
printf("\nsize of " BOLD "[string]" RESET " using " BOLD "sizeof(string) = " FG_RED "%lu" RESET, sizeof(string));
NEWLINE;
printf("size of " BOLD "[string[0]]" RESET " using " BOLD "sizeof(string[0]) = " FG_RED "%lu" RESET, sizeof(string[0]));
NEWLINE;
printf("size of " BOLD "[string]" RESET " using " BOLD "strlen(string) = " FG_RED "%lu" RESET, strlen(string));
NEWLINE;

```

***Output***

```txt
size of [string] using sizeof(string) = 38
size of [string[0]] using sizeof(string[0]) = 1
size of [string] using strlen(string) = 37

```

---

#### [Character Iteration & Null Terminator](#string)

***Syntax C***

```c
for (int index = 0; index < (int)sizeof(string) - 1; index++) {
    printf("Character at index = " BOLD FG_GREEN "%d" RESET " is: " BOLD FG_RED "%c%c" RESET, index, string[index], LINEFEED);
}
printf("Character at index = " BOLD FG_GREEN "%lu" RESET " is: " BOLD FG_RED "\\0%c" RESET, sizeof(string) - 1, LINEFEED);

```

***Output***

```txt
Character at index = 0 is: T
Character at index = 1 is: h
Character at index = 2 is: i
Character at index = 3 is: s
Character at index = 4 is:  
Character at index = 5 is: i
Character at index = 6 is: s
Character at index = 7 is:  
Character at index = 8 is: a
Character at index = 9 is:  
Character at index = 10 is: s
Character at index = 11 is: t
Character at index = 12 is: r
Character at index = 13 is: i
Character at index = 14 is: n
Character at index = 15 is: g
Character at index = 16 is: .
Character at index = 17 is:  
Character at index = 18 is: A
Character at index = 19 is: r
Character at index = 20 is: r
Character at index = 21 is: a
Character at index = 22 is: y
Character at index = 23 is:  
Character at index = 24 is: o
Character at index = 25 is: f
Character at index = 26 is:  
Character at index = 27 is: C
Character at index = 28 is: h
Character at index = 29 is: a
Character at index = 30 is: r
Character at index = 31 is: a
Character at index = 32 is: c
Character at index = 33 is: t
Character at index = 34 is: e
Character at index = 35 is: r
Character at index = 36 is: s
Character at index = 37 is: \0

```

---

### [Integer](#sections)

> * [`1D Integer Array Memory & Sizing`](#1d-integer-array-memory--sizing)
> 
> 

#### [1D Integer Array Memory & Sizing](#integer)

***Syntax C***

```c
int integers[10];
int sizeOfIntegerArray = (int)(sizeof(integers) / sizeof(integers[0]));

for (int index = 0; index < sizeOfIntegerArray; index++) { 
    integers[index] = index; 
    printf("%d", integers[index]);  
}
NEWLINE; 

printf("Memory allocated for " BOLD "[integers]" RESET " =  " BOLD FG_GREEN "%lu" RESET, sizeof(integers));
NEWLINE;
printf("Memory allocated for " BOLD "[integers[0]]" RESET " =  " BOLD FG_GREEN "%lu" RESET, sizeof(integers[0]));
NEWLINE;
printf("Actual array variable size for " BOLD "[integers]" RESET " =  " BOLD FG_GREEN "%d" RESET, sizeOfIntegerArray);
NEWLINE;

```

***Output***

```txt
0123456789

Memory allocated for [integers] =  40

Memory allocated for [integers[0]] =  4

Actual array variable size for [integers] =  10
```

---

### [Multi-Dimensional Arrays](#sections)

> * [`2D Integer Array Sizing & Traversal`](#2d-integer-array-sizing--traversal)
> * [`2D String Pointer Array Traversal`](#2d-string-pointer-array-traversal)
> 
> 

***Compilation Failure Context (Variable Dimensions)***

> [!CAUTION]
> ```c
> // Variable-length arrays cannot be initialized at declaration
> int sizeX = 2;
> int sizeY = 4;
> int twoDimensionalArrayFailed[sizeX][sizeY] = {
>     {0, 1, 0, 1},
>     {0, 0, 1, 1}
> };
> 
> ```
> 
> 

#### [2D Integer Array Sizing & Traversal](#multi-dimensional-arrays)

***Syntax C***

```c
int twoDimensionalArrayExample1[2][4] = {
    {0, 1, 0, 1}, 
    {0, 0, 1, 1}
};

int totalElements = (int)(sizeof(twoDimensionalArrayExample1) / sizeof(twoDimensionalArrayExample1[0][0]));
int rows = (int)(sizeof(twoDimensionalArrayExample1) / sizeof(twoDimensionalArrayExample1[0]));
int cols = (int)(sizeof(twoDimensionalArrayExample1[0]) / sizeof(twoDimensionalArrayExample1[0][0]));

printf("Memory allocated for " BOLD "[twoDimensionalArrayExample1]" RESET " =  " BOLD FG_GREEN "%lu" RESET, sizeof(twoDimensionalArrayExample1));
NEWLINE;
printf("Memory allocated for " BOLD "[twoDimensionalArrayExample1[0]]" RESET " =  " BOLD FG_GREEN "%lu" RESET, sizeof(twoDimensionalArrayExample1[0]));
NEWLINE;
printf("Total number of single integer cell " BOLD "[twoDimensionalArrayExample1[0][0]]" RESET " =  " BOLD FG_GREEN "%d" RESET, totalElements);
NEWLINE;

for (int rowIndex = 0; rowIndex < rows; rowIndex++) { 
    for (int colIndex = 0; colIndex < cols; colIndex++) {
        printf("Value at [%d][%d] = " BOLD FG_GREEN "%d" RESET "%c", rowIndex, colIndex, twoDimensionalArrayExample1[rowIndex][colIndex], LINEFEED);
    }
}
NEWLINE;

```

***Output***

```txt
Memory allocated for [twoDimensionalArrayExample1] =  32

Memory allocated for [twoDimensionalArrayExample1[0]] =  16

Total number of single integer cell [twoDimensionalArrayExample1[0][0]] =  8

Value at [0][0] = 0
Value at [0][1] = 1
Value at [0][2] = 0
Value at [0][3] = 1
Value at [1][0] = 0
Value at [1][1] = 0
Value at [1][2] = 1
Value at [1][3] = 1
```

---

#### [2D String Pointer Array Traversal](#multi-dimensional-arrays)

***Syntax C***

```c
const char *twoDimensionalStringArray[2][3] = {
    {"index[0][0]", "index[0][1]", "index[0][2]"},
    {"index[1][0]", "index[1][1]", "index[1][2]"}
};

int stringRows = (int)(sizeof(twoDimensionalStringArray) / sizeof(twoDimensionalStringArray[0]));
int stringCols = (int)(sizeof(twoDimensionalStringArray[0]) / sizeof(twoDimensionalStringArray[0][0]));

printf("Memory allocated for " BOLD "[twoDimensionalStringArray]" RESET " (6 pointers) =  " BOLD FG_GREEN "%lu" RESET " bytes", sizeof(twoDimensionalStringArray));
NEWLINE;

for (int rowIndex = 0; rowIndex < stringRows; rowIndex++) {
    for (int colIndex = 0; colIndex < stringCols; colIndex++) {
        printf("String at [%d][%d] = " BOLD FG_COLOR(190) "%s" RESET "%c", rowIndex, colIndex, twoDimensionalStringArray[rowIndex][colIndex], LINEFEED);
    }
}
NEWLINE;

```

***Output***

```txt
Memory allocated for [twoDimensionalStringArray] (6 pointers) =  48 bytes

String at [0][0] = index[0][0]
String at [0][1] = index[0][1]
String at [0][2] = index[0][2]
String at [1][0] = index[1][0]
String at [1][1] = index[1][1]
String at [1][2] = index[1][2]

```

[:arrow_up: Return to Top](#array)
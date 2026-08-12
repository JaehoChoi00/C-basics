# Variables Extended

[:arrow_left: Return to Main README](../README.md)  

[:arrow_left: Return to Variables](Variables.md)

> This is a full rundown of the [`ExtendedVariables.c`](/variables/ExtendedVariables.c) file    
> This file includes the [`VariableConstants.h`](/variables/VariableConstants.h) header
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/variables/   
> gcc ExtendedVariables.c -o ExtendedVariables && ./ExtendedVariables  
> ```
>
> <br>

## Sections:

> * [`Binary Operations`](#binary-operations)
> * [`Binary Literal`](#binary-literal)
> * [`Bit Manipulation`](#bit-manipulation)
> * [`Signed vs Unsigned`](#signed-vs-unsigned)


### [Binary Operations](#sections)

***C Sytnax***
```c
// Binary Operations
int num = 255;

// 8 bits

int firstBit = (num>>0) & 1;
int secondBit = (num>>1) & 1;
int thirdBit = (num>>2) & 1;
int forthBit = (num>>3) & 1;
int fifthBit = (num>>4) & 1;
int sixthBit = (num>>5) & 1;
int seventhBit = (num>>6) & 1;
int eighthBit = (num>>7) & 1;

printf("%d%d%d%d%d%d%d%d%c", eighthBit, seventhBit, sixthBit, fifthBit, 
                            forthBit, thirdBit, secondBit, firstBit, LINEFEED);
```

***Output***

```bash
11111111
```

***Another way***

```c
void printBinary(unsigned char binaryLiteral) {
    for (int i = 7; i >= 0; i--) {
        int bit = (binaryLiteral >> i) & 1; 
        printf("%d", bit);
    }
    NEWLINE;
}
```

***Call***

```c
printBinary(num);
```

***Output***

```bash
11111111
```

### [Binary Literal](#sections)

***Utility Functions***

```c
// Declaration
void printBinaryWithString(const char stringPrint[], unsigned char binaryLiteral);

// Definition
void printBinaryWithString(const char stringPrint[], unsigned char binaryLiteral) {
    printf("%s", stringPrint);
    for (int i = 7; i >= 0; i--) {
        int bit = (binaryLiteral >> i) & 1; 
        printf("%d", bit);
    }
    NEWLINE;
}
```


***C Syntax***

```c
// Modern C23 Binary Literal
unsigned char binaryLiteral = 0b11111111;
printBinary(binaryLiteral);

// Hexadecimal notation
binaryLiteral = 0xFF;
printBinary(binaryLiteral);
```

***Output***

```bash
11111111

11111111
```

### [Bit Manipulation](#sections)

***C Syntax***

```c
binaryLiteral = 0b00000000;
printBinaryWithString("Before: ", binaryLiteral);

binaryLiteral |= (1 << 0); // OR
printBinaryWithString("After |= (1 << 0) : ", binaryLiteral);

binaryLiteral = 0b00000000;
printBinaryWithString("Before: ", binaryLiteral);

binaryLiteral ^= (1 << 2); // XOR
printBinaryWithString("After ^= (1 << 2) : ", binaryLiteral);

binaryLiteral = 0b00100000;

printBinaryWithString("Before: ", binaryLiteral);

binaryLiteral &= ~(1 << 5);

printBinaryWithString("After &= ~(1 << 5): ", binaryLiteral);
```

***Output***

```txt
Before: 00000000

After |= (1 << 0) : 00000001

Before: 00000000

After ^= (1 << 2) : 00000100

Before: 00000000

After &= ~(1 << 5) : 00000000

```

### [Signed vs Unsigned](#sections)

***C Syntax***

```c
num = -128;
signed char signedLiteral = (signed char)(num & 0xFF);
printBinaryWithString("Signed ", signedLiteral);
unsigned char unsignedLiteral = (unsigned char)(num & 0xFF);
printBinaryWithString("Unsigned ", unsignedLiteral);

signed char signedVariable = 255;
unsigned char unsignedVariable = 255;

printf("SignedVariable: " FG_GREEN "%d%c" RESET , signedVariable, LINEFEED);
printf("UnsignedVariable: " FG_RED "%u" RESET, unsignedVariable);
NEWLINE;
printf( FG_GREEN "%d" RESET " < " FG_RED "%u" RESET, signedVariable, unsignedVariable);
NEWLINE;

signedVariable = -1;
unsignedVariable = -1;

printf("SignedVariable: " FG_GREEN "%d%c" RESET , signedVariable, LINEFEED);
printf("UnsignedVariable: " FG_RED "%u" RESET, unsignedVariable);
NEWLINE;
printf( FG_GREEN "%d" RESET " < " FG_RED "%u" RESET, signedVariable, unsignedVariable);
NEWLINE;
```

***Output***

```txt
Signed 10000000

Unsigned 10000000

SignedVariable: -1
UnsignedVariable: 255

-1 < 255

SignedVariable: -1
UnsignedVariable: 255

-1 < 255
```

### [Bit-Fields Restriction](#sections)

***Declaration***

```c
struct VariableRestriction {
    unsigned int coinFlip    : 1;  // Uses exactly 1 bit (0 or 1)
    unsigned int threeModes  : 2;  // Uses exactly 2 bits (0 to 3)
    unsigned int errorType  : 4;  // Uses exactly 4 bits (0 to 15)
};
```

***C Syntax***

```c
struct VariableRestriction restriction;

restriction.coinFlip = 1;      // Max 1 bit (can be 0 or 1)
restriction.threeModes = 3;    // Max 2 bits (can be 0 to 3)
restriction.errorType = 15;    // Max 4 bits (can be 0 to 15)

printf("Coin Flip: %u\n", restriction.coinFlip);
printf("Mode Select: %u\n", restriction.threeModes);
printf("Error Code: %u\n", restriction.errorType);

restriction.coinFlip = 2; 
printf("Coin Flip when assigned 2: " FG_RED "%u" RESET, restriction.coinFlip); 
```

***Output***

```txt
Coin Flip: 1
Mode Select: 3
Error Code: 15
Coin Flip when assigned 2: 0
```
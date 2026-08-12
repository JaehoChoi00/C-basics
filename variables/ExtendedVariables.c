#include <stdio.h>
#include <stdlib.h>

#include "VariableConstants.h"

void printBinary(unsigned char binaryLiteral);
void printBinaryWithString(const char stringPrint[], unsigned char binaryLiteral);

struct VariableRestriction {
    unsigned int coinFlip    : 1;  // Uses exactly 1 bit (0 or 1)
    unsigned int threeModes  : 2;  // Uses exactly 2 bits (0 to 3)
    unsigned int errorType  : 4;  // Uses exactly 4 bits (0 to 15)
};

int main() {
    // Binary Operations
    printf(BOLD UNDERLINE "%c[Binary Operations]" RESET, LINEFEED);
    NEWLINE;

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
    
    printBinary(num);

    // Modern C23 Binary Literal
    unsigned char binaryLiteral = 0b11111111;
    printBinary(binaryLiteral);

    // Hexadecimal notation
    binaryLiteral = 0xFF;
    printBinary(binaryLiteral);

    // Bit Manipulation
    printf(BOLD UNDERLINE "%c[Bit Manipulation]" RESET, LINEFEED);
    NEWLINE;

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

    // Signed vs Unsigned
    printf(BOLD UNDERLINE "%c[Signed vs Unsigneds]" RESET, LINEFEED);
    NEWLINE;

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
    
    // Bit-Fields in Structs
    printf(BOLD UNDERLINE "%c[Bit-Fields Restriction]" RESET, LINEFEED);
    NEWLINE;

    struct VariableRestriction restriction;
    
    restriction.coinFlip = 1;      // Max 1 bit (can be 0 or 1)
    restriction.threeModes = 3;    // Max 2 bits (can be 0 to 3)
    restriction.errorType = 15;    // Max 4 bits (can be 0 to 15)

    printf("Coin Flip: %u\n", restriction.coinFlip);
    printf("Mode Select: %u\n", restriction.threeModes);
    printf("Error Code: %u\n", restriction.errorType);

    restriction.coinFlip = 2; 
    printf("Coin Flip when assigned 2: " FG_RED "%u" RESET, 
            restriction.coinFlip); 

    NEWLINE;

    return 0;
}

void printBinary(unsigned char binaryLiteral) {
    for (int i = 7; i >= 0; i--) {
        int bit = (binaryLiteral >> i) & 1; 
        printf("%d", bit);
    }
    NEWLINE;
}

void printBinaryWithString(const char stringPrint[], unsigned char binaryLiteral) {
    printf("%s", stringPrint);
    for (int i = 7; i >= 0; i--) {
        int bit = (binaryLiteral >> i) & 1; 
        printf("%d", bit);
    }
    NEWLINE;
}
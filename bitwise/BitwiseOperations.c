#include <stdio.h>
#include <stdint.h>

#include "../variables/VariableConstants.h"

// Binary Printing Helpers

void printBinary8(uint8_t binary);
void printBinary16(uint16_t binary);
void printBinary32(uint32_t binary);
void printBinary64(uint64_t binary);

// Bit Manipulation Helpers

uint8_t setBit8(uint8_t binary, uint8_t bitIndex);
uint16_t setBit16(uint16_t binary, uint16_t bitIndex);
uint32_t setBit32(uint32_t binary, uint32_t bitIndex);
uint64_t setBit64(uint64_t binary, uint64_t bitIndex);

uint8_t clearBit8(uint8_t binary, uint8_t bitIndex);
uint16_t clearBit16(uint16_t binary, uint16_t bitIndex);
uint32_t clearBit32(uint32_t binary, uint32_t bitIndex);
uint64_t clearBit64(uint64_t binary, uint64_t bitIndex);

uint8_t toggleBit8(uint8_t binary, uint8_t bitIndex);
uint16_t toggleBit16(uint16_t binary, uint16_t bitIndex);
uint32_t toggleBit32(uint32_t binary, uint32_t bitIndex);
uint64_t toggleBit64(uint64_t binary, uint64_t bitIndex);

uint8_t checkBit8(uint8_t binary, uint8_t bitIndex);
uint16_t checkBit16(uint16_t binary, uint16_t bitIndex);
uint32_t checkBit32(uint32_t binary, uint32_t bitIndex);
uint64_t checkBit64(uint64_t binary, uint64_t bitIndex);


// Bitwise Logical Operations

void bitwiseLogicalOperations(void) {
    printf(BOLD UNDERLINE "Bitwise Logical Operations" RESET "\n");

    uint8_t binaryDeclaredWith4Bits = 0b1111;

    printf("Declared Binary: " BOLD FG_GREEN); printBinary8(binaryDeclaredWith4Bits); NEWLINE;
    printf("Binary to variable: " BOLD FG_GREEN "%d" RESET, binaryDeclaredWith4Bits); NEWLINE;

    uint8_t binaryAbit8 = 0b00001100;
    uint8_t binaryBbit8 = 0b00001010;

    printf("Binary A: " BOLD FG_GREEN); printBinary8(binaryAbit8); NEWLINE;
    printf("Binary B: " BOLD FG_GREEN); printBinary8(binaryBbit8); NEWLINE;

    printf("AND A & B: " BOLD FG_GREEN); printBinary8(binaryAbit8 & binaryBbit8); NEWLINE;
    printf("OR A | B: " BOLD FG_GREEN); printBinary8(binaryAbit8 | binaryBbit8); NEWLINE;
    printf("XOR A ^ B: " BOLD FG_GREEN); printBinary8(binaryAbit8 ^ binaryBbit8); NEWLINE;
    printf("NOT ~A: " BOLD FG_GREEN); printBinary8((uint8_t)~binaryAbit8); NEWLINE;

    printf(BOLD "LEFT SHIFT by 2. A << 2: " FG_GREEN); printBinary8(binaryAbit8); printf(RESET BOLD " -> " FG_RED); printBinary8(binaryAbit8 << 2); NEWLINE;
    printf(BOLD "RIGHT SHIFT by 2. A >> 2: " FG_GREEN); printBinary8(binaryAbit8); printf(RESET BOLD " -> " FG_RED); printBinary8(binaryAbit8 >> 2); NEWLINE;
}


// 8-Bit Manipulation

void bitMaskingManipulation8(void) {
    printf(BOLD UNDERLINE "8-Bit Manipulation (Masking)" RESET "\n");

    uint8_t binary = 0b00000000;

    printf("Initial Binary: " BOLD FG_COLOR(147)); printBinary8(binary); NEWLINE;

    binary = setBit8(binary, 3);
    printf("Turn on Bit index 3: " BOLD FG_COLOR(147)); printBinary8(binary); NEWLINE;

    binary = toggleBit8(binary, 3);
    printf("Toggle Bit index 3: " BOLD FG_COLOR(147)); printBinary8(binary); NEWLINE;

    binary = setBit8(binary, 5);
    printf("Turn on Bit index 5: " BOLD FG_COLOR(147)); printBinary8(binary); NEWLINE;

    printf("Check Bit index 5: " BOLD FG_GREEN "%s" RESET, checkBit8(binary, 5) ? "ENABLED" : "DISABLED"); NEWLINE;

    binary = clearBit8(binary, 5);
    printf("Clear Bit index 5: " BOLD FG_COLOR(147)); printBinary8(binary); NEWLINE;

    printf("Check Bit index 5: " BOLD FG_GREEN "%s" RESET, checkBit8(binary, 5) ? "ENABLED" : "DISABLED"); NEWLINE;
}


// 16-Bit Manipulation

void bitMaskingManipulation16(void) {
    printf(BOLD UNDERLINE "16-Bit Manipulation (Masking)" RESET "\n");

    uint16_t binary = 0x0000;

    printf("Initial Binary: " BOLD FG_COLOR(147)); printBinary16(binary); NEWLINE;

    binary = setBit16(binary, 3);
    printf("Turn on Bit index 3: " BOLD FG_COLOR(147)); printBinary16(binary); NEWLINE;

    binary = setBit16(binary, 8);
    printf("Turn on Bit index 8: " BOLD FG_COLOR(147)); printBinary16(binary); NEWLINE;

    printf("Check Bit index 8: " BOLD FG_GREEN "%s" RESET, checkBit16(binary, 8) ? "ENABLED" : "DISABLED"); NEWLINE;

    binary = toggleBit16(binary, 8);
    printf("Toggle Bit index 8: " BOLD FG_COLOR(147)); printBinary16(binary); NEWLINE;

    binary = clearBit16(binary, 3);
    printf("Clear Bit index 3: " BOLD FG_COLOR(147)); printBinary16(binary); NEWLINE;

    printf("Check Bit index 3: " BOLD FG_GREEN "%s" RESET, checkBit16(binary, 3) ? "ENABLED" : "DISABLED"); NEWLINE;
}


// 32-Bit Manipulation

void bitMaskingManipulation32(void) {
    printf(BOLD UNDERLINE "32-Bit Manipulation (Masking)" RESET "\n");

    uint32_t binary = 0x00000000U;

    printf("Initial Binary: " BOLD FG_COLOR(147)); printBinary32(binary); NEWLINE;

    binary = setBit32(binary, 7);
    printf("Turn on Bit index 7: " BOLD FG_COLOR(147)); printBinary32(binary); NEWLINE;

    binary = setBit32(binary, 16);
    printf("Turn on Bit index 16: " BOLD FG_COLOR(147)); printBinary32(binary); NEWLINE;

    printf("Check Bit index 16: " BOLD FG_GREEN "%s" RESET, checkBit32(binary, 16) ? "ENABLED" : "DISABLED"); NEWLINE;

    binary = toggleBit32(binary, 16);
    printf("Toggle Bit index 16: " BOLD FG_COLOR(147)); printBinary32(binary); NEWLINE;

    binary = clearBit32(binary, 7);
    printf("Clear Bit index 7: " BOLD FG_COLOR(147)); printBinary32(binary); NEWLINE;

    printf("Check Bit index 7: " BOLD FG_GREEN "%s" RESET, checkBit32(binary, 7) ? "ENABLED" : "DISABLED"); NEWLINE;
}


// 64-Bit Manipulation

void bitMaskingManipulation64(void) {
    printf(BOLD UNDERLINE "64-Bit Manipulation (Large Stride Masking)" RESET "\n");

    uint64_t binary = 0ULL;

    printf("Initial Binary: " BOLD FG_COLOR(147)); printBinary64(binary); NEWLINE;

    binary = setBit64(binary, 60);
    printf("Turn on Bit index 60: " BOLD FG_COLOR(147)); printBinary64(binary); NEWLINE;

    binary = toggleBit64(binary, 60);
    printf("Toggle Bit index 60: " BOLD FG_COLOR(147)); printBinary64(binary); NEWLINE;

    binary = setBit64(binary, 63);
    printf("Turn on Bit index 63: " BOLD FG_COLOR(147)); printBinary64(binary); NEWLINE;

    printf("Check Bit index 63: " BOLD FG_GREEN "%s" RESET, checkBit64(binary, 63) ? "ENABLED" : "DISABLED"); NEWLINE;

    binary = clearBit64(binary, 63);
    printf("Clear Bit index 63: " BOLD FG_COLOR(147)); printBinary64(binary); NEWLINE;

    printf("Check Bit index 63: " BOLD FG_GREEN "%s" RESET, checkBit64(binary, 63) ? "ENABLED" : "DISABLED"); NEWLINE;
}


// Main

int main() {
    printf(BOLD UNDERLINE "%c[Bitwise Operations Demonstration]" RESET, LINEFEED);
    NEWLINE;

    bitwiseLogicalOperations();
    NEWLINE;

    bitMaskingManipulation8();
    NEWLINE;

    bitMaskingManipulation16();
    NEWLINE;

    bitMaskingManipulation32();
    NEWLINE;

    bitMaskingManipulation64();
    NEWLINE;

    return 0;
}


// Binary Printing Helpers

void printBinary8(uint8_t binary) { for (int bit = 7; bit >= 0; bit--) { printf("%d", (binary >> bit) & 1); } }
void printBinary16(uint16_t binary) { for (int bit = 15; bit >= 0; bit--) { printf("%d", (binary >> bit) & 1); } }
void printBinary32(uint32_t binary) { for (int bit = 31; bit >= 0; bit--) { printf("%d", (binary >> bit) & 1); } }
void printBinary64(uint64_t binary) { for (int bit = 63; bit >= 0; bit--) { printf("%d", (int)((binary >> bit) & 1)); } }


// Set Bit Helpers

uint8_t setBit8(uint8_t binary, uint8_t bitIndex) { return binary | ((uint8_t)1 << bitIndex); }
uint16_t setBit16(uint16_t binary, uint16_t bitIndex) { return binary | ((uint16_t)1 << bitIndex); }
uint32_t setBit32(uint32_t binary, uint32_t bitIndex) { return binary | ((uint32_t)1 << bitIndex); }
uint64_t setBit64(uint64_t binary, uint64_t bitIndex) { return binary | ((uint64_t)1 << bitIndex); }


// Clear Bit Helpers

uint8_t clearBit8(uint8_t binary, uint8_t bitIndex) { return binary & ~((uint8_t)1 << bitIndex); }
uint16_t clearBit16(uint16_t binary, uint16_t bitIndex) { return binary & ~((uint16_t)1 << bitIndex); }
uint32_t clearBit32(uint32_t binary, uint32_t bitIndex) { return binary & ~((uint32_t)1 << bitIndex); }
uint64_t clearBit64(uint64_t binary, uint64_t bitIndex) { return binary & ~((uint64_t)1 << bitIndex); }


// Toggle Bit Helpers

uint8_t toggleBit8(uint8_t binary, uint8_t bitIndex) { return binary ^ ((uint8_t)1 << bitIndex); }
uint16_t toggleBit16(uint16_t binary, uint16_t bitIndex) { return binary ^ ((uint16_t)1 << bitIndex); }
uint32_t toggleBit32(uint32_t binary, uint32_t bitIndex) { return binary ^ ((uint32_t)1 << bitIndex); }
uint64_t toggleBit64(uint64_t binary, uint64_t bitIndex) { return binary ^ ((uint64_t)1 << bitIndex); }


// Check Bit Helpers

uint8_t checkBit8(uint8_t binary, uint8_t bitIndex) { return (binary & ((uint8_t)1 << bitIndex)) != 0; }
uint16_t checkBit16(uint16_t binary, uint16_t bitIndex) { return (binary & ((uint16_t)1 << bitIndex)) != 0; }
uint32_t checkBit32(uint32_t binary, uint32_t bitIndex) { return (binary & ((uint32_t)1 << bitIndex)) != 0; }
uint64_t checkBit64(uint64_t binary, uint64_t bitIndex) { return (binary & ((uint64_t)1 << bitIndex)) != 0; }

# Bitwise Operations

[:arrow_left: Return to Main README](../README.md)

> This is a full rundown of the [`BitwiseOperations.c`](/bitwise/BitwiseOperations.c) file
>
> ---
>
> **Terminal code for compiling and running:**
> ```bash
> cd C\ Basics/bitwise/
> gcc BitwiseOperations.c -o BitwiseOperations && ./BitwiseOperations
> ```
>
> <br>

## Sections

- [Bitwise Operations](#bitwise-operations)
  - [Sections](#sections)
    - [Helper Functions Implementation](#helper-functions-implementation)
      - [Binary Printing Utility Functions](#binary-printing-utility-functions)
      - [Bit Masking Helper Functions (Set, Clear, Toggle, Check)](#bit-masking-helper-functions-set-clear-toggle-check)
    - [Bitwise Logical Operations](#bitwise-logical-operations)
      - [Binary Declaration \& Integer Representation](#binary-declaration--integer-representation)
      - [Bitwise AND, OR, XOR, NOT \& Bit Shifts](#bitwise-and-or-xor-not--bit-shifts)
    - [Bit Masking \& Manipulation](#bit-masking--manipulation)
      - [8-Bit Masking Operations](#8-bit-masking-operations)
      - [16-Bit Masking Operations](#16-bit-masking-operations)
      - [32-Bit Masking Operations](#32-bit-masking-operations)
      - [64-Bit Large Stride Masking](#64-bit-large-stride-masking)


---

### [Helper Functions Implementation](#sections)

> * [`Binary Printing Utility Functions`](#binary-printing-utility-functions)
> * [`Bit Masking Helper Functions (Set, Clear, Toggle, Check)`](#bit-masking-helper-functions-set-clear-toggle-check)


#### [Binary Printing Utility Functions](#helper-functions-implementation)

**Syntax C**

```c
void printBinary8(uint8_t binary) { for (int bit = 7; bit >= 0; bit--) { printf("%d", (binary >> bit) & 1); } }

void printBinary16(uint16_t binary) { for (int bit = 15; bit >= 0; bit--) { printf("%d", (binary >> bit) & 1); } }

void printBinary32(uint32_t binary) { for (int bit = 31; bit >= 0; bit--) { printf("%d", (binary >> bit) & 1); } }

void printBinary64(uint64_t binary) { for (int bit = 63; bit >= 0; bit--) { printf("%d", (int)((binary >> bit) & 1)); } }
````

These functions print the binary representation of an unsigned integer from its most significant bit to its least significant bit.

The available functions support:

```text
uint8_t   → 8 bits
uint16_t  → 16 bits
uint32_t  → 32 bits
uint64_t  → 64 bits
```

The `bit` variable starts at the highest bit index and decreases to `0`.

For example, `printBinary8()` starts at bit `7` and finishes at bit `0`.

---

#### [Bit Masking Helper Functions (Set, Clear, Toggle, Check)](#helper-functions-implementation)

**Syntax C**

```c
// Set Bit Operations

uint8_t setBit8(uint8_t binary, uint8_t bitIndex) { return binary | ((uint8_t)1 << bitIndex); }
uint16_t setBit16(uint16_t binary, uint16_t bitIndex) { return binary | ((uint16_t)1 << bitIndex); }
uint32_t setBit32(uint32_t binary, uint32_t bitIndex) { return binary | ((uint32_t)1 << bitIndex); }
uint64_t setBit64(uint64_t binary, uint64_t bitIndex) { return binary | ((uint64_t)1 << bitIndex); }


// Clear Bit Operations

uint8_t clearBit8(uint8_t binary, uint8_t bitIndex) { return binary & ~((uint8_t)1 << bitIndex); }
uint16_t clearBit16(uint16_t binary, uint16_t bitIndex) { return binary & ~((uint16_t)1 << bitIndex); }
uint32_t clearBit32(uint32_t binary, uint32_t bitIndex) { return binary & ~((uint32_t)1 << bitIndex); }
uint64_t clearBit64(uint64_t binary, uint64_t bitIndex) { return binary & ~((uint64_t)1 << bitIndex); }


// Toggle Bit Operations

uint8_t toggleBit8(uint8_t binary, uint8_t bitIndex) { return binary ^ ((uint8_t)1 << bitIndex); }
uint16_t toggleBit16(uint16_t binary, uint16_t bitIndex) { return binary ^ ((uint16_t)1 << bitIndex); }
uint32_t toggleBit32(uint32_t binary, uint32_t bitIndex) { return binary ^ ((uint32_t)1 << bitIndex); }
uint64_t toggleBit64(uint64_t binary, uint64_t bitIndex) { return binary ^ ((uint64_t)1 << bitIndex); }


// Check Bit Operations

uint8_t checkBit8(uint8_t binary, uint8_t bitIndex) { return (binary & ((uint8_t)1 << bitIndex)) != 0; }
uint16_t checkBit16(uint16_t binary, uint16_t bitIndex) { return (binary & ((uint16_t)1 << bitIndex)) != 0; }
uint32_t checkBit32(uint32_t binary, uint32_t bitIndex) { return (binary & ((uint32_t)1 << bitIndex)) != 0; }
uint64_t checkBit64(uint64_t binary, uint64_t bitIndex) { return (binary & ((uint64_t)1 << bitIndex)) != 0; }
```

The helper functions perform four fundamental bit manipulation operations:

```text
SET
    Turn a specific bit ON.

CLEAR
    Turn a specific bit OFF.

TOGGLE
    Reverse the current state of a specific bit.

CHECK
    Determine whether a specific bit is ON or OFF.
```

Each operation has an implementation for 8-bit, 16-bit, 32-bit and 64-bit unsigned integers.

The explicit integer casts on `1` ensure that the mask is constructed using the corresponding integer width.

---

### [Bitwise Logical Operations](#bitwise-logical-operations)

> * [`Binary Declaration & Integer Representation`](#binary-declaration--integer-representation)
> * [`Bitwise AND, OR, XOR, NOT & Bit Shifts`](#bitwise-and-or-xor-not--bit-shifts)

#### [Binary Declaration & Integer Representation](#bitwise-logical-operations)

**Syntax C**

```c
uint8_t binaryDeclaredWith4Bits = 0b1111;

printf("Declared Binary: " BOLD FG_GREEN); printBinary8(binaryDeclaredWith4Bits); NEWLINE;
printf("Binary to variable: " BOLD FG_GREEN "%d" RESET, binaryDeclaredWith4Bits); NEWLINE;
```

**Output**

```text
Declared Binary: 00001111

Binary to variable: 15
```

A binary literal can be assigned directly to an integer variable.

Although only four `1` bits are explicitly declared:

```text
1111
```

the `uint8_t` variable contains 8 bits, so the binary printing helper displays:

```text
00001111
```

The same value can also be represented as the decimal integer:

```text
15
```

---

#### [Bitwise AND, OR, XOR, NOT & Bit Shifts](#bitwise-logical-operations)

**Syntax C**

```c
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
```

**Output**

```text
Binary A: 00001100

Binary B: 00001010

AND A & B: 00001000

OR A | B: 00001110

XOR A ^ B: 00000110

NOT ~A: 11110011

LEFT SHIFT by 2. A << 2: 00001100 -> 00110000

RIGHT SHIFT by 2. A >> 2: 00001100 -> 00000011
```

The logical operations demonstrated are:

```text
&   AND
|   OR
^   XOR
~   NOT
<<  Left Shift
>>  Right Shift
```

---

### [Bit Masking & Manipulation](#sections)

> * [`8-Bit Masking Operations`](#8-bit-masking-operations)
> * [`16-Bit Masking Operations`](#16-bit-masking-operations)
> * [`32-Bit Masking Operations`](#32-bit-masking-operations)
> * [`64-Bit Large Stride Masking`](#64-bit-large-stride-masking)

#### [8-Bit Masking Operations](#bit-masking--manipulation)

**Syntax C**

```c
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
```

**Output**

```text
Initial Binary: 00000000

Turn on Bit index 3: 00001000

Toggle Bit index 3: 00000000

Turn on Bit index 5: 00100000

Check Bit index 5: ENABLED

Clear Bit index 5: 00000000

Check Bit index 5: DISABLED
```

---

#### [16-Bit Masking Operations](#bit-masking--manipulation)

**Syntax C**

```c
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
```

**Output**

```text
Initial Binary: 0000000000000000

Turn on Bit index 3: 0000000000001000

Turn on Bit index 8: 0000000100001000

Check Bit index 8: ENABLED

Toggle Bit index 8: 0000000000001000

Clear Bit index 3: 0000000000000000

Check Bit index 3: DISABLED
```

---

#### [32-Bit Masking Operations](#bit-masking--manipulation)

**Syntax C**

```c
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
```

**Output**

```text
Initial Binary: 00000000000000000000000000000000

Turn on Bit index 7: 00000000000000000000000010000000

Turn on Bit index 16: 00000000000000010000000010000000

Check Bit index 16: ENABLED

Toggle Bit index 16: 00000000000000000000000010000000

Clear Bit index 7: 00000000000000000000000000000000

Check Bit index 7: DISABLED
```

> [!NOTE]
> The valid bit indices are:
> 
> ```text
> 0 → 31
> ```

---

#### [64-Bit Large Stride Masking](#bit-masking--manipulation)

**Syntax C**

```c
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
```

**Output**

```text
Initial Binary: 0000000000000000000000000000000000000000000000000000000000000000

Turn on Bit index 60: 0001000000000000000000000000000000000000000000000000000000000000

Toggle Bit index 60: 0000000000000000000000000000000000000000000000000000000000000000

Turn on Bit index 63: 1000000000000000000000000000000000000000000000000000000000000000

Check Bit index 63: ENABLED

Clear Bit index 63: 0000000000000000000000000000000000000000000000000000000000000000

Check Bit index 63: DISABLED
```

> [!NOTE]
> The valid bit indices are:
> 
> ```text
> 0 → 63
> ```
> 
> Bit `63` is the most significant bit of the `uint64_t` value, while bit `0` is the least significant bit.

---




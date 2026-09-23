# Constants

[:arrow_left: Return to Main README](../README.md)

> This is a full rundown of the [Constants.c](/constants/Constants.c) file  
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/constants/   
> gcc Constants.c -o Constants && ./Constants  
> ```
> <br>

## Sections:

> * [`Text Substitution & Enum Literals (No Memory Address)`](#text-substitution--enum-literals-no-memory-address)
> * [`Const Variables (Occupies Memory Address)`](#const-variables-occupies-memory-address)

---

### [Text Substitution & Enum Literals (No Memory Address)](#sections)

***Creation***

```c
#define PREPROCESSOR_MACRO 1000

enum {
    ENUM_X = 2,
    ENUM_Y = 4
};

void noAddressConstants(void) {
    printf(BOLD UNDERLINE "Text Substitution & Enum Literals (No Memory Address)" RESET "\n");

    int fixedArray[ENUM_X][ENUM_Y];

    printf("  Macro Value: %d\n", PREPROCESSOR_MACRO);
    printf("  Enum X Value: %d\n", ENUM_X);
    printf("  Enum Y Value: %d\n", ENUM_Y);
    printf("  Array Memory Allocated: %zu Bytes\n", sizeof(fixedArray));
}
```

***Syntax C***

```c
// Syntax: #define NAME value
// Syntax: enum { NAME = value };

noAddressConstants();
NEWLINE;
```

***Output***

```txt
Text Substitution & Enum Literals (No Memory Address)
  Macro Value: 1000
  Enum X Value: 2
  Enum Y Value: 4
  Array Memory Allocated: 32 Bytes
```

---

### [Const Variables (Occupies Memory Address)](#sections)

***Creation***

```c
const int GLOBAL_CONST_VARIABLE = 500;

void allocatedMemoryConstants(void) {
    printf(BOLD UNDERLINE "Const Variables (Occupies Memory Address)" RESET "\n");

    const double LOCAL_CONST_VARIABLE = 3.14159;

    printf("  Global Const Value: %d | Memory Address: %p\n", GLOBAL_CONST_VARIABLE, (void*)&GLOBAL_CONST_VARIABLE);
    printf("  Local Const Value: %.5f | Memory Address: %p\n", LOCAL_CONST_VARIABLE, (void*)&LOCAL_CONST_VARIABLE);
}
```

***Syntax C***

```c
// Syntax: const type name = value;

allocatedMemoryConstants();
NEWLINE;
```

***Output***

```txt
Const Variables (Occupies Memory Address)
  Global Const Value: 500 | Memory Address: 0x55def45f2010
  Local Const Value: 3.14159 | Memory Address: 0x7ffd594be4f8
```

[:arrow_up: Return to Top](#constants)
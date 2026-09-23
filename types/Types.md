# Types

[:arrow_left: Return to Main README](../README.md)

> This is a full rundown of these files:
> * [`Conversions.c`](/types/Conversions.c) 
> * [`Enums.c`](/types/Enums.c)
> * [`StandardTypes.c`](/types/StandardTypeHeaders.c) 
> * [`Typedef.c`](/types/Typedef.c) 
>
> ---
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/types/   
> gcc Conversions.c -o Conversions && ./Conversions  
> 
> gcc Enums.c -o Enums && ./Enums
> 
> gcc StandardTypeHeaders.c -o StandardTypeHeaders && ./StandardTypeHeaders 
> 
> gcc Typedef.c -o Typedef && ./Typedef  
> ```
> <br>

## Sections:

> * [`Conversions`](#conversions)
> * [`Enumerations`](#enumerations)
> * [`Standard Type Headers`](#standard-type-headers)
> * [`Typedef`](#typedef)

---

### [Conversions](#sections)

***Syntax C***

```c
char asciiChar = '1';
int convertedIntegerDigit = asciiChar - '0';

printf("ASCII character '" FG_GREEN "%c" RESET "' has underlying value %d\n", asciiChar, asciiChar);
printf("Character converted to int (bit - '0'): " FG_COLOR(50) "%d" RESET "%c", convertedIntegerDigit, LINEFEED);
NEWLINE;

int sourceIntegerDigit = 0;
char backToChar = sourceIntegerDigit + '0';

printf("Raw integer value: " FG_COLOR(50) "%d" RESET "%c", sourceIntegerDigit, LINEFEED);
printf("Int converted back to character (value + '0'): '" FG_GREEN "%c" RESET "' (ASCII %d)%c", backToChar, backToChar, LINEFEED);
LINEBREAK;
```

***Output***

```txt
ASCII character '1' has underlying value 49
Character converted to int (bit - '0'): 1

Raw integer value: 0
Int converted back to character (value + '0'): '0' (ASCII 48)
```

---

### [Enumerations](#sections)

> * [`Automatic Sequential Enumeration`](#automatic-sequential-enumeration)
> * [`Automatic Sequential Drift Enumeration`](#automatic-sequential-drift-enumeration)
> * [`Explicit Customized Enumeration`](#explicit-customized-enumeration)

#### [Automatic Sequential Enumeration](#enumerations)

***Creation***

```c
typedef enum {
    AUTOMATIC_ENUM_VALUE_ZERO,       
    AUTOMATIC_ENUM_VALUE_ONE,
    AUTOMATIC_ENUM_VALUE_TWO    
} AutomaticSequentialEnum;
```

***Syntax C***

```c
AutomaticSequentialEnum sequentialEnumInstance = AUTOMATIC_ENUM_VALUE_ONE;
printf("Default automatic sequential enum value (ZERO): " FG_GREEN "%d" RESET "%c", AUTOMATIC_ENUM_VALUE_ZERO, LINEFEED);
printf("Default automatic sequential enum value (ONE): " FG_GREEN "%d" RESET "%c", sequentialEnumInstance, LINEFEED);
NEWLINE;
```

***Output***

```txt
Default automatic sequential enum value (ZERO): 0
Default automatic sequential enum value (ONE): 1
```

---

#### [Automatic Sequential Drift Enumeration](#enumerations)

***Creation***

```c
typedef enum {
    EXPLICIT_STARTING_POINT_TEN = 10,
    AUTOMATIC_ENUM_VALUE_ELEVEN,     
    AUTOMATIC_ENUM_VALUE_TWELVE       
} EnumSequentialDriftExample;
```

***Syntax C***

```c
printf("Explicit starting point enum value (TEN): " FG_BLUE "%d" RESET "%c", EXPLICIT_STARTING_POINT_TEN, LINEFEED);
printf("Automatic sequential drift enum value (ELEVEN): " FG_BLUE "%d" RESET "%c", AUTOMATIC_DRIFT_VALUE_ELEVEN, LINEFEED);
NEWLINE;
```

***Output***

```txt
Explicit starting point enum value (TEN): 10
Automatic sequential drift enum value (ELEVEN): 11
```

---

#### [Explicit Customized Enumeration](#enumerations)

***Creation***

```c
typedef enum {
    EXPLICIT_ENUM_VALUE_TWO = 2,
    EXPLICIT_ENUM_VALUE_FOUR = 4,       
    EXPLICIT_ENUM_VALUE_SIX = 6,        
    EXPLICIT_ENUM_VALUE_EIGHT = 8   
} ExplicitCustomizedEnum;
```

***Syntax C***

```c
ExplicitCustomizedEnum customizedEnumInstance = EXPLICIT_ENUM_VALUE_EIGHT;
printf("Explicit customized discrete enum value (TWO): " FG_COLOR(50) "%d" RESET "%c", EXPLICIT_ENUM_VALUE_TWO, LINEFEED);
printf("Explicit customized discrete enum value (EIGHT): " FG_COLOR(50) "%d" RESET "%c", customizedEnumInstance, LINEFEED);
LINEBREAK;
```

***Output***

```txt
Explicit customized discrete enum value (TWO): 2
Explicit customized discrete enum value (EIGHT): 8
```

---

### [Standard Type Headers](#sections)

***Syntax C***

```c
// Core Types, Limits, and Properties
#include <stdint.h>   // Exact-width integer types (int32_t, uint64_t)
#include <inttypes.h> // Format conversion macros for printf/scanf
#include <stddef.h>   // size_t, ptrdiff_t, NULL, offsetof
#include <stdbool.h>  // bool, true, false (Keywords in C23)
#include <limits.h>   // Sizes and limits of integer types
#include <float.h>    // Limits of floating-point types

// Variadic & Unicode Types
#include <stdarg.h>   // va_list for variable argument functions

// Environment & Context Specific Types
#include <time.h>     // time_t, clock_t, struct tm
#include <math.h>     // float_t, double_t
#include <signal.h>   // sig_atomic_t
#include <wchar.h>    // wint_t, wchar_t

int main(void) {
    return 0;
}
```

---

### [Typedef](#sections)

> * [`Typedef Primitive Alias`](#typedef-primitive-alias)
> * [`Typedef Structure Alias`](#typedef-structure-alias)
> * [`Typedef Function Pointer Alias`](#typedef-function-pointer-alias)

#### [Typedef Primitive Alias](#typedef)

***Creation***

```c
typedef int IntAlias;
```

***Syntax C***

```c
IntAlias specialInt = 64;
```

---

#### [Typedef Structure Alias](#typedef)

***Creation***

```c
typedef struct {
    int firstIntVariable;
    char stringSize50[50]; 
} StructTypedef;
```

***Syntax C***

```c
StructTypedef instanceOne = {specialInt, "This is a string with size 30"};

printf(BOLD "%s | Internal Int: %d" RESET "%c", instanceOne.stringSize50, instanceOne.firstIntVariable, LINEFEED);
NEWLINE;
```

***Output***

```txt
This is a string with size 30 | Internal Int: 64
```

---

#### [Typedef Function Pointer Alias](#typedef)

***Creation***

```c
typedef void (*LogNotificationFunctionPointer)(int);

void dummyLogCallback(int executionValue) {
    printf("Callback function triggered with value: " FG_GREEN "%d" RESET "%c", executionValue, LINEFEED);
}
```

***Syntax C***

```c
LogNotificationFunctionPointer eventCallback = dummyLogCallback;

eventCallback(instanceOne.firstIntVariable);
LINEBREAK;
```

***Output***

```txt
Callback function triggered with value: 64
```

[:arrow_up: Return to Top](#types)
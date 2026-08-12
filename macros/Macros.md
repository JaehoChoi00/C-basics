# Macros

[:arrow_left: Return to Main README](../README.md)

> This is a full rundown of the [Macros.c](/types/Conversions.c) file  
> This file includes the [VariableConstants.h](/variables/VariableConstants.h) header
>
> ---
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/macros/   
> gcc Macros.c -o Macros && ./Macros  
> ``` 
> 
> <br>

---

***Syntax***

```c
#define NAME "VALUE"
```

***Macro Headers***

```h
#ifndef MACROS_H
#define MACROS_H

#define ADD(x, y) ((x) + (y))
#define SUB(x, y) ((x) - (y))
#define MUL(x, y) ((x) * (y))
#define DIV(x, y) ((x) / (y))
#define DIV_FLOAT(x, y) ((double)(x) / (double)(y))

#define NORMAL

#endif
```

```c
#include <stdio.h>
#include <stdlib.h>
#include "Macros.h"

#include "../variables/VariableConstants.h"

int main() {
    #ifdef DEBUG
        printf("%cThis is " BOLD FG_RED "DEBUG" RESET " mode%c", LINEFEED, LINEFEED);
    #endif

    #ifdef NORMAL
        printf("%cThis is " BOLD FG_COLOR(33) "NORMAL" RESET " mode%c", LINEFEED, LINEFEED);

        int a = 1;
        int b = 2;

        if (argc >= 3) {
            a = atoi(argv[1]);
            b = atoi(argv[2]);
        }
        printf("%d + %d = %d%c", a, b, ADD(a, b), LINEFEED);
        printf("%d - %d = %d%c", a, b, SUB(a, b), LINEFEED);
        printf("%d * %d = %d%c", a, b, MUL(a, b), LINEFEED);
        printf("%d / %d = %d%c", a, b, DIV(a, b), LINEFEED);
        printf("%d / %d = %lf%c", a, b, DIV_FLOAT(a, b), LINEFEED);
        
    #endif
}
```

***Running***

```bash
./Macros 5 6
```

***Output***

```txt

This is NORMAL mode
5 + 6 = 11
5 - 6 = -1
5 * 6 = 30
5 / 6 = 0
5 / 6 = 0.833333
```
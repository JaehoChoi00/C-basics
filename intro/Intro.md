# Introduction

[:arrow_left: Return to Main README](../README.md)

> This is a full rundown of these files:
> * [`Print.c`](/intro/Print.c) 
> * [`PrintExtended.c`](/intro/PrintExtended.c) 
> * [`Main.c`](/intro/Main.c) 
>
> ---
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/intro/   
> gcc Print.c -o Print && ./Print  
> 
> gcc PrintExtended.c -o PrintExtended && ./PrintExtended
> 
> gcc Main.c -o Main && ./Main
> ``` 
> <br>

## Sections:

> * [`Printf`](#printf)
> * [`Printf Extended`](#printf-extended)
> * [`int main()`](#int-main)

---

### [Printf](#sections)

```c 
    // This is a comment
```

```c 
    #include <stdio.h> // <- standard input output c library.

    int main() {
        printf("This is a string printed by the printf() function from the stdio library\n"); 
        return 0; // <- Signals the end of the program
    }
```

### [Printf Extended](#sections)

<code>%n specifier</code> [`documentation`](<https://www.geeksforgeeks.org/c/g-fact-31/>)

> [!TIP]
>
> ***`printf` is Turing-complete primarily because of the `%n` format specifier, which allows the function to write data back into memory***
>
> For something to be **Turing Complete**:
> 1. **Unbounded Memory Manipulation (Read & Write)**
>     * Usiing the `%n` and `*`
> 2. **Conditional Branching (If/Else Logic)**
>     * Array indexing & pointer offset arithmetics are possible
> 3. **Unbounded Looping or Recursion**
>     * If memory manipulation is true, `printf` can have it's execution pointer to loop back to the beginning of the format string.

### [int main()](#sections)

***Syntax***

```c
#include <stdio.h>
#include "../variables/VariableConstants.h"

int main(int argc, char *argv[]) {

    printf("\nArguement count: [%d]\n" argc);

    printf("\nArguement value for index [0]: [%s]\n" argv[0]);

    return 0;
}
```

***Running***

```unix
./fileName Hello World do you see me\?
```

***Output***

```unix
Arguement count: [7]

Arguement value for index [0]: [./soloBuild/Main]
_____________________________________________

The exact arguements written to run this:

./soloBuild/Main Hello World, do you see me? 
```
<br>

[:arrow_up: Return to Top](#introduction)
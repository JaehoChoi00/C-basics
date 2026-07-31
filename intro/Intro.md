# The Printf

[:arrow_left: Return to Main README](../README.md)

---

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

<br>

## %n specifier [`documentation`](<https://www.geeksforgeeks.org/c/g-fact-31/>)

> ***FUN FACT:***
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
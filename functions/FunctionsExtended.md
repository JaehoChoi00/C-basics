# Functions

[:arrow_left: Return to Main README](../README.md)  
[:arrow_left: Return to Functions README](Functions.md)

> This is a full rundown of the [`FunctionsExtended.c`](/functions/FunctionsExtended.c) file  
> This file includes the [`VariableConstants.h`](/variables/VariableConstants.h) header
>
> ---
> 
> **Terminal code for compiling and running**:  
> ```unix
> cd C\ Basics/functions/   
> gcc FunctionsExtended.c -o FunctionsExtended && ./FunctionsExtended  
> ``` 
> 
> <br>

---

## Sections:

> * [`Inline Functions`](#inline-functions)
> * [`Function Pointers`](#function-pointers)

---


### [Inline Functions](#sections)

***Declaration***

```c
static inline int add(int a, int b);
```

***Definition***

```c
static inline int add(int a, int b) {
    return a + b;
}
```

***C Syntax***

```c
printf("1 + 2 = " FG_GREEN "%d" RESET, add(1, 2));
```

After compile

```c
printf("1 + 2 = " FG_GREEN "%d" RESET, (1 + 2));
```

***Output***

```txt
1 + 2 = 3
```

### [Function Pointers](#sections)

***C Syntax***

```c
int (*functionPointer)(int, int);

functionPointer = add;

printf("Calling " BOLD FG_YELLOW "add" RESET " via " BOLD FG_COLOR(190)"functionPointer(5 + 3)" " = " FG_GREEN "%d" RESET, functionPointer(5, 3));
```

***Output***

```txt
Calling add via functionPointer(5 + 3) = 8
```
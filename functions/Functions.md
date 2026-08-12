# Functions

[:arrow_left: Return to Main README](../README.md)  
[:arrow_right: move to Extended Functions README](FunctionsExtended.md)

> This is a full rundown of the [`Functions.c`](/functions/Functions.c) file  
> This file includes the [`VariableConstants.h`](/variables/VariableConstants.h) header
>
> ---
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/functions/   
> gcc Functions.c -o Functions && ./Functions  
> ``` 
> 
> <br>

## Sections:

> * [`Declarations`](#declarations)
> * [`Definitions`](#definitions)
> * [`Testing`](testing)

---

### [Declarations](#sections)

***C Syntax***

```c
void functionName();
void functionWithParameters(char string[]);
char* functionWithReturn();
void functionWithStringManipulation(char string[]);

```

### [Defintions](#sections)

***C Syntax***

```c
void functionName() {
    printf("This is a function");
}

void functionWithParameters(char string[]) {
    printf("The is a function with a" BOLD FG_GREEN " %s" RESET, string);
}

char* functionWithReturn() {
    return "Message to Distribute";
}

void functionWithStringManipulation(char string[]) {
    strcpy(string, "Well received");
}
```

### [Testing](#sections)

***C Syntax***

```c
functionName();
NEWLINE;
functionWithParameters("Parameter");
NEWLINE;
printf("Message from function: " BOLD FG_RED "%s" RESET, functionWithReturn());
NEWLINE;
char message[] = "Did you receive?";
functionWithStringManipulation(message);
printf("Sending Message " BOLD FG_GREEN "\"Did you receive?\"" RESET " to " BOLD "functionWithStringManipulation." RESET " New message: " BOLD FG_RED "\"%s\"" RESET, message);
NEWLINE;
```

***Output***

```txt
This is a function

The is a function with a Parameter

Message from function: Message to Distribute

Sending Message "Did you receive?" to functionWithStringManipulation. New message: "Well received"
```
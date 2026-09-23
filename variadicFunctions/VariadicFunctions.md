# Variadic Functions

[:arrow_left: Return to Main README](../README.md)

> This is a full rundown of the [VariadicFunctions.c](/variadicFunctions/VariadicFunctions.c) file

> ***Terminal code for compiling and running***:

> ```bash
> cd C\ Basics/functions/
> gcc VariadicFunctions.c -o VariadicFunctions && ./VariadicFunctions
> ```

> [!TIP]
>
> Variadic is a technical word meaing - [`Taking a variable number of Arguments`](https://en.wiktionary.org/wiki/variadic#:~:text=(programming%2C%20mathematics%2C%20linguistics)%20Taking%20a%20variable%20number%20of%20arguments%3B)  
> Hence, `Variadic Function` means - a function that takes a variable number of arguments.

## Sections:

> * [`Variadic Type Tags`](#variadic-type-tags)
> * [`Variadic Argument Traversal`](#variadic-argument-traversal)
> * [`Variadic Argument Cloning`](#variadic-argument-cloning)
> * [`Formatted Variadic Output`](#formatted-variadic-output)

---

### [Variadic Type Tags](#sections)

***Creation***

```c
typedef enum {
    TYPE_TAG_INTEGER,
    TYPE_TAG_DOUBLE,
    TYPE_TAG_CHARACTER
} VariadicTypeTag;
```

***Syntax C***

```c
// Syntax: typedef enum { ... } VariadicTypeTag

VariadicTypeTag processingTags[] = {
    TYPE_TAG_INTEGER,
    TYPE_TAG_DOUBLE,
    TYPE_TAG_CHARACTER
};
```

---

### [Variadic Argument Traversal](#sections)

***Creation***

```c
void demonstrateVariadicMechanics(int explicitArgumentCount, const VariadicTypeTag* typeTagsArray, ...) {
    va_list primaryVariadicArguments;

    va_start(primaryVariadicArguments, typeTagsArray);

    for (int argumentIterator = 0; argumentIterator < explicitArgumentCount; argumentIterator++) {
        switch (typeTagsArray[argumentIterator]) {
            case TYPE_TAG_INTEGER: {
                int retrievedInteger = va_arg(primaryVariadicArguments, int);

                printf("  Index [%d] | Size Stride: " BOLD "%zu Bytes" RESET " | Type: [int]    | Value: " FG_GREEN "%d" RESET "\n",
                    argumentIterator, sizeof(int), retrievedInteger);

                break;
            }

            case TYPE_TAG_DOUBLE: {
                double retrievedDouble = va_arg(primaryVariadicArguments, double);

                printf("  Index [%d] | Size Stride: " BOLD "%zu Bytes" RESET " | Type: [double] | Value: " FG_CYAN "%.5f" RESET "\n",
                    argumentIterator, sizeof(double), retrievedDouble);

                break;
            }

            case TYPE_TAG_CHARACTER: {
                char retrievedCharacter = (char)va_arg(primaryVariadicArguments, int);

                printf("  Index [%d] | Size Stride: " BOLD "%zu Bytes" RESET " | Type: [char]   | Value: " FG_MAGENTA "%c" RESET "\n",
                    argumentIterator, sizeof(int), retrievedCharacter);

                break;
            }
        }
    }

    va_end(primaryVariadicArguments);
}
```

***Syntax C***

```c
// Syntax: va_list, va_start(), va_arg(), va_end()

VariadicTypeTag processingTags[] = {
    TYPE_TAG_INTEGER,
    TYPE_TAG_DOUBLE,
    TYPE_TAG_CHARACTER
};

demonstrateVariadicMechanics(3, processingTags, 2048, 3.14159, 'Z');

NEWLINE;
```

***Output***

```txt
Index [0] | Size Stride: 4 Bytes | Type: [int]    | Value: 2048
Index [1] | Size Stride: 8 Bytes | Type: [double] | Value: 3.14159
Index [2] | Size Stride: 4 Bytes | Type: [char]   | Value: Z
```

---

### [Variadic Argument Cloning](#sections)

***Creation***

```c
va_list primaryVariadicArguments;
va_list clonedVariadicArguments;

va_start(primaryVariadicArguments, typeTagsArray);
va_copy(clonedVariadicArguments, primaryVariadicArguments);

printf(FG_YELLOW "Metadata Analysis -> Total Dynamic Arguments to Retrieve: %d\n" RESET, explicitArgumentCount);

va_end(clonedVariadicArguments);
```

***Syntax C***

```c
// Syntax: va_copy(destination, source)

va_copy(clonedVariadicArguments, primaryVariadicArguments);

va_end(clonedVariadicArguments);
```

---

### [Formatted Variadic Output](#sections)

***Creation***

```c
void printFormattedMessage(const char* literalTagString, const char* formatStringMessage, ...) {
    printf("[%s%s%s] ", BOLD, literalTagString, RESET);

    va_list outputVariadicArguments;

    va_start(outputVariadicArguments, formatStringMessage);
    vprintf(formatStringMessage, outputVariadicArguments);
    va_end(outputVariadicArguments);
}
```

***Syntax C***

```c
// Syntax: vprintf(format, va_list)

printFormattedMessage("ALPHA", "First integer value is %d and second integer value is %d\n", 100, 200);

printFormattedMessage("BETA", "Character stream output: %c\n", 'X');

LINEBREAK;
```

***Output***

```txt
[ALPHA] First integer value is 100 and second integer value is 200

[BETA] Character stream output: X
```

[:arrow_up: Return to Top](#variadic-functions)
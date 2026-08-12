#include <stdio.h>
#include "../variables/VariableConstants.h"

static inline int add(int a, int b);

int main() {
    // Functions Extended
    printf(BOLD UNDERLINE "%c[Functions Extended]%c" RESET, LINEFEED, LINEFEED);
    LINEBREAK;

    // Inline Functions
    printf(BOLD UNDERLINE "%c[Inline Functions]" RESET, LINEFEED);
    NEWLINE;
    printf("1 + 2 = " FG_GREEN "%d" RESET, add(1, 2));
    NEWLINE;

    // Function Pointers
    printf(BOLD UNDERLINE "%c[Function Pointers]" RESET, LINEFEED);
    NEWLINE;

    int (*functionPointer)(int, int);

    functionPointer = add;

    printf("Calling " BOLD FG_YELLOW "add" RESET " via " BOLD FG_COLOR(190)"functionPointer(5 + 3)" " = " FG_GREEN "%d" RESET, functionPointer(5, 3));
    NEWLINE;

    return 0;
}

static inline int add(int a, int b) {
    return a + b;
}
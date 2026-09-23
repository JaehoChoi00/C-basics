#include <stdio.h>

#include "../variables/VariableConstants.h"

typedef int IntAlias;

typedef struct {
    int firstIntVariable;
    char stringSize30[30];
} StructTypedef;

typedef void (*FunctionPointer)(int);

void someCallback(int executionValue) {
    printf("Callback function triggered with value: " FG_GREEN "%d" RESET "%c", executionValue, LINEFEED);
}

int main(void) {
    printf(BOLD UNDERLINE "%c[Typedef Aliases]" RESET, LINEFEED);
    NEWLINE;
    
    IntAlias specialInt = 64;

    StructTypedef instanceOne = {specialInt, "This is a string with size 30"};

    FunctionPointer eventCallback = someCallback;

    printf(BOLD "%s | Internal Int: %d" RESET "%c", instanceOne.stringSize30, instanceOne.firstIntVariable, LINEFEED);
    NEWLINE;

    eventCallback(instanceOne.firstIntVariable);
    LINEBREAK;

    return 0;
}

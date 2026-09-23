#include <stdio.h>

#include "../variables/VariableConstants.h"

#define PREPROCESSOR_MACRO 1000

enum {
    ENUM_X = 2,
    ENUM_Y = 4
};

const int GLOBAL_CONST_VARIABLE = 500;

void noAddressConstants(void) {
    printf(BOLD UNDERLINE "Text Substitution & Enum Literals (No Memory Address)" RESET "\n");

    int fixedArray[ENUM_X][ENUM_Y];

    printf("  Macro Value: %d\n", PREPROCESSOR_MACRO);
    printf("  Enum X Value: %d\n", ENUM_X);
    printf("  Enum Y Value: %d\n", ENUM_Y);
    printf("  Array Memory Allocated: %zu Bytes\n", sizeof(fixedArray));
}

void allocatedMemoryConstants(void) {
    printf(BOLD UNDERLINE "Const Variables (Occupies Memory Address)" RESET "\n");

    const double LOCAL_CONST_VARIABLE = 3.14159;

    printf("  Global Const Value: %d | Memory Address: %p\n", GLOBAL_CONST_VARIABLE, (void*)&GLOBAL_CONST_VARIABLE);
    printf("  Local Const Value: %.5f | Memory Address: %p\n", LOCAL_CONST_VARIABLE, (void*)&LOCAL_CONST_VARIABLE);
}

int main() {
    printf(BOLD UNDERLINE "%c[Constants Demonstration]" RESET, LINEFEED);
    NEWLINE;

    noAddressConstants();
    NEWLINE;

    allocatedMemoryConstants();
    NEWLINE;

    return 0;
}

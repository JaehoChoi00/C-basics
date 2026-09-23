#include <stdio.h>
#include <string.h>

#include "../variables/VariableConstants.h"

void arrayDecay(int *arr);
void passByReference(int *x);
void dummyFunction(int parameter);

int main()
{
    // Addresses & Simple Pointers
    printf(BOLD UNDERLINE "%c[Addresses & Simple Pointers]" RESET, LINEFEED);
    NEWLINE;

    int originalValue = 64;

    int *pointerToValue = &originalValue;

    printf("Original value: (originalValue) = " BOLD FG_GREEN "%d" RESET "%c", originalValue, LINEFEED);
    printf("Original value address: (&originalValue) = " BOLD FG_COLOR(190) "%p" RESET "%c", &originalValue, LINEFEED);
    printf("Address stored as pointer: (pointerToValue) = " BOLD FG_COLOR(190) "%p" RESET "%c", pointerToValue, LINEFEED);
    printf("Dereferenced pointer: (*pointerToValue) = " BOLD FG_RED "%d" RESET, *pointerToValue);
    NEWLINE;

    int archivedOriginal = *pointerToValue;
    *pointerToValue = 99;
    printf("Pointer value modified (*pointerToValue = 99): (archivedOriginal) = " BOLD FG_GREEN "%d" RESET " | (originalValue) = " BOLD FG_RED "%d" RESET, archivedOriginal, originalValue);
    NEWLINE;

    printf(BOLD UNDERLINE "%c[Pointer Decay & Pass-By-Reference]" RESET, LINEFEED);
    NEWLINE;

    // Basic Type: Pure copy (Pass-By-Reference)
    int testNum = 10;
    printf("Before passByReference: " BOLD FG_GREEN "%d" RESET "%c", testNum, LINEFEED);
    passByReference(&testNum);
    printf("After passByReference (Changed): " BOLD FG_GREEN "%d" RESET, testNum);
    NEWLINE;

    // Array Type: Automatically decays into a pointer
    int decayArray[5] = {10, 20, 30, 40, 50};
    printf("Size of array in main scope using sizeof: " BOLD FG_RED "%lu" RESET " bytes%c", sizeof(decayArray), LINEFEED);

    arrayDecay(decayArray);
    NEWLINE;

    void (*functionPointer)(int parameter) = dummyFunction;
    printf("Address of dummyFunction using function name: " BOLD FG_COLOR(190) "%p" RESET "%c", (void *)dummyFunction, LINEFEED);
    printf("Address stored in functionPointer: " BOLD FG_COLOR(190) "%p" RESET, (void *)functionPointer);

    functionPointer(originalValue);
    NEWLINE;

    return 0;
}

void passByReference(int *x) { *x = 999; }

void arrayDecay(int *arr) {
    printf("Size of array inside function scope using sizeof: " BOLD FG_RED "%lu" RESET " bytes (Decayed to pointer!)", sizeof(arr));
}

void dummyFunction(int parameter) {
    printf("Executed dummyFunction via pointer (functionPointer(originalValue);). Received value: " BOLD FG_GREEN "%d" RESET, parameter);
}

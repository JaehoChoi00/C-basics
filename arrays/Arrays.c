#include <stdio.h>
#include "../variables/VariableConstants.h"

int main() {
    // Character array = string
    char string[] = "This is a string.";

    printf(BOLD FG_GREEN "%c%s%c" RESET, LINEFEED, string, LINEFEED);

    printf("\nsize of [string] = " BOLD FG_RED "%lu%c%c" RESET, sizeof(string), LINEFEED, LINEFEED);

    for (int index = 0; index < sizeof(string); index++) {
        printf("Character at index = " BOLD FG_GREEN "%d" RESET " is: " BOLD FG_RED "%c%c" RESET, index, string[index], LINEFEED);
    }
    
    // Integer array
    int integers[10]; // Array of 10 integers

    for (int index = 0; index < 10; index++) { 
        integers[index] = index; // Populate the array from 0 to 9
        printf("%d", integers[index]);  
    }
    printf("%c", LINEFEED);

    int tenNumbers[10];
    printf("%c%lu%c", LINEFEED, sizeof(tenNumbers), LINEFEED);

    for (int index = 0; index < 10; index++) { 
        tenNumbers[index] = index; 
    }
    
    return 0;
}
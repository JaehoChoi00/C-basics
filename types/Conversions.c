#include <stdio.h>

#include "../variables/VariableConstants.h"

int main() {
    // ASCII Type Conversion
    printf(BOLD UNDERLINE "%c[ASCII Type Conversion]" RESET, LINEFEED);
    NEWLINE;

    char asciiChar = '1';
    // Subtracting '0' (48) shifts the ASCII table value down to a raw integer
    int integerBit = asciiChar - '0'; 
    
    printf("ASCII character '" FG_GREEN "%c" RESET "' has underlying value %d\n", asciiChar, asciiChar);
    printf("Character converted to int (bit - '0'): " FG_COLOR(50) "%d" RESET "%c", integerBit, LINEFEED);
    NEWLINE;

    int rawInteger = 0;
    // Adding '0' (48) shifts the raw integer up into the displayable character range
    char backToChar = rawInteger + '0';

    printf("Raw integer value: " FG_COLOR(50) "%d" RESET "%c", rawInteger, LINEFEED);
    printf("Int converted back to character (value + '0'): '" FG_GREEN "%c" RESET "' (ASCII %d)%c", backToChar, backToChar, LINEFEED);
    NEWLINE;
}
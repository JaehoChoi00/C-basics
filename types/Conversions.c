#include <stdio.h>

#include "../variables/VariableConstants.h"

int main(void) {
    printf(BOLD UNDERLINE "%c[ASCII Type Conversion]" RESET, LINEFEED);
    NEWLINE;

    char asciiChar = '1';
    int convertedIntegerDigit = asciiChar - '0';

    printf("ASCII character '" FG_GREEN "%c" RESET "' has underlying value %d\n", asciiChar, asciiChar);
    printf("Character converted to int (bit - '0'): " FG_COLOR(50) "%d" RESET "%c", convertedIntegerDigit, LINEFEED);
    NEWLINE;

    int sourceIntegerDigit = 0;
    char backToChar = sourceIntegerDigit + '0';

    printf("Raw integer value: " FG_COLOR(50) "%d" RESET "%c", sourceIntegerDigit, LINEFEED);
    printf("Int converted back to character (value + '0'): '" FG_GREEN "%c" RESET "' (ASCII %d)%c", backToChar, backToChar, LINEFEED);
    LINEBREAK;

    return 0;
}

#include <stdio.h>
#include <string.h>

#include "../variables/VariableConstants.h"

void characterArrays(void) {
    printf(BOLD UNDERLINE "\nArrays" RESET "\n");

    char character = 'C';
    char string[] = "This is a string. Array of Characters";
    
    printf(BOLD FG_COLOR(190) "%c%c%c" RESET, LINEFEED, character, LINEFEED);
    printf(BOLD FG_GREEN "%c%s%c" RESET, LINEFEED, string, LINEFEED);

    printf("\nsize of " BOLD "[string]" RESET " using " BOLD "sizeof(string) = " FG_RED "%lu" RESET, sizeof(string));
    NEWLINE;
    printf("size of " BOLD "[string[0]]" RESET " using " BOLD "sizeof(string[0]) = " FG_RED "%lu" RESET, sizeof(string[0]));
    NEWLINE;
    printf("size of " BOLD "[string]" RESET " using " BOLD "strlen(string) = " FG_RED "%lu" RESET, strlen(string));
    NEWLINE;

    for (int index = 0; index < (int)sizeof(string) - 1; index++) {
        printf("Character at index = " BOLD FG_GREEN "%d" RESET " is: " BOLD FG_RED "%c%c" RESET, index, string[index], LINEFEED);
    }
    printf("Character at index = " BOLD FG_GREEN "%lu" RESET " is: " BOLD FG_RED "\\0%c" RESET, sizeof(string) - 1, LINEFEED);
}

void integerArrays(void) {
    printf(BOLD UNDERLINE "Integer Arrays" RESET "\n");

    int integers[10];
    int sizeOfIntegerArray = (int)(sizeof(integers) / sizeof(integers[0]));

    for (int index = 0; index < sizeOfIntegerArray; index++) { 
        integers[index] = index; 
        printf("%d", integers[index]);  
    }
    NEWLINE; 

    printf("Memory allocated for " BOLD "[integers]" RESET " =  " BOLD FG_GREEN "%lu" RESET, sizeof(integers));
    NEWLINE;
    printf("Memory allocated for " BOLD "[integers[0]]" RESET " =  " BOLD FG_GREEN "%lu" RESET, sizeof(integers[0]));
    NEWLINE;
    printf("Actual array variable size for " BOLD "[integers]" RESET " =  " BOLD FG_GREEN "%d" RESET, sizeOfIntegerArray);
    NEWLINE;
}

void multiDimensionalArrays(void) {
    printf(BOLD UNDERLINE "Multi-Dimensional Arrays" RESET "\n");

    int twoDimensionalArrayExample1[2][4] = {
        {0, 1, 0, 1}, 
        {0, 0, 1, 1}
    };
    
    int totalElements = (int)(sizeof(twoDimensionalArrayExample1) / sizeof(twoDimensionalArrayExample1[0][0]));
    int rows = (int)(sizeof(twoDimensionalArrayExample1) / sizeof(twoDimensionalArrayExample1[0]));
    int cols = (int)(sizeof(twoDimensionalArrayExample1[0]) / sizeof(twoDimensionalArrayExample1[0][0]));

    printf("Memory allocated for " BOLD "[twoDimensionalArrayExample1]" RESET " =  " BOLD FG_GREEN "%lu" RESET, sizeof(twoDimensionalArrayExample1));
    NEWLINE;
    printf("Memory allocated for " BOLD "[twoDimensionalArrayExample1[0]]" RESET " =  " BOLD FG_GREEN "%lu" RESET, sizeof(twoDimensionalArrayExample1[0]));
    NEWLINE;
    printf("Total number of single integer cell " BOLD "[twoDimensionalArrayExample1[0][0]]" RESET " =  " BOLD FG_GREEN "%d" RESET, totalElements);
    NEWLINE;

    for (int rowIndex = 0; rowIndex < rows; rowIndex++) { 
        for (int colIndex = 0; colIndex < cols; colIndex++) {
            printf("Value at [%d][%d] = " BOLD FG_GREEN "%d" RESET "%c", rowIndex, colIndex, twoDimensionalArrayExample1[rowIndex][colIndex], LINEFEED);
        }
    }
    NEWLINE;

    const char *twoDimensionalStringArray[2][3] = {
        {"index[0][0]", "index[0][1]", "index[0][2]"},
        {"index[1][0]", "index[1][1]", "index[1][2]"}
    };

    int stringRows = (int)(sizeof(twoDimensionalStringArray) / sizeof(twoDimensionalStringArray[0]));
    int stringCols = (int)(sizeof(twoDimensionalStringArray[0]) / sizeof(twoDimensionalStringArray[0][0]));

    printf("Memory allocated for " BOLD "[twoDimensionalStringArray]" RESET " (6 pointers) =  " BOLD FG_GREEN "%lu" RESET " bytes", sizeof(twoDimensionalStringArray));
    NEWLINE;

    for (int rowIndex = 0; rowIndex < stringRows; rowIndex++) {
        for (int colIndex = 0; colIndex < stringCols; colIndex++) {
            printf("String at [%d][%d] = " BOLD FG_COLOR(190) "%s" RESET "%c", rowIndex, colIndex, twoDimensionalStringArray[rowIndex][colIndex], LINEFEED);
        }
    }
    NEWLINE;
}

int main() {
    characterArrays();
    NEWLINE;

    integerArrays();

    multiDimensionalArrays();

    return 0;
}

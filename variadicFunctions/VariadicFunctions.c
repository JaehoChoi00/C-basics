#include <stdio.h>
#include <stdarg.h>

#include "../variables/VariableConstants.h"

typedef enum {
    TYPE_TAG_INTEGER,
    TYPE_TAG_DOUBLE,
    TYPE_TAG_CHARACTER
} VariadicTypeTag;

void demonstrateVariadicMechanics(int explicitArgumentCount, const VariadicTypeTag* typeTagsArray, ...);
void printFormattedMessage(const char* literalTagString, const char* formatStringMessage, ...);

int main(void) {
    printf(BOLD UNDERLINE "%c[Variadic Functions and Stack Retrieval]" RESET, LINEFEED);
    NEWLINE;

    VariadicTypeTag processingTags[] = { TYPE_TAG_INTEGER, TYPE_TAG_DOUBLE, TYPE_TAG_CHARACTER };

    demonstrateVariadicMechanics(3, processingTags, 2048, 3.14159, 'Z');
    NEWLINE;

    printFormattedMessage("ALPHA", "First integer value is %d and second integer value is %d\n", 100, 200);
    printFormattedMessage("BETA", "Character stream output: %c\n", 'X');
    LINEBREAK;

    return 0;
}

void demonstrateVariadicMechanics(int explicitArgumentCount, const VariadicTypeTag* typeTagsArray, ...) {
    va_list primaryVariadicArguments;
    va_list clonedVariadicArguments;

    va_start(primaryVariadicArguments, typeTagsArray);
    va_copy(clonedVariadicArguments, primaryVariadicArguments);

    printf(FG_YELLOW "Metadata Analysis -> Total Dynamic Arguments to Retrieve: %d\n" RESET, explicitArgumentCount);
    
    va_end(clonedVariadicArguments);

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

void printFormattedMessage(const char* literalTagString, const char* formatStringMessage, ...) {
    printf("[%s%s%s] ", BOLD, literalTagString, RESET);

    va_list outputVariadicArguments;
    va_start(outputVariadicArguments, formatStringMessage);
    
    vprintf(formatStringMessage, outputVariadicArguments); 
    
    va_end(outputVariadicArguments);
}

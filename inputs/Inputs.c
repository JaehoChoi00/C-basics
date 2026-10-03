#include <stdio.h>
#include <string.h>
#include "../variables/VariableConstants.h"

void clearInputBuffer();
void getIntegerInput(int *number);
void getCharacterInput(int *number, char *character);
void getWordInput(char string[]);
void getSentenceInput(char string[], int size);

int main() {
    printf(BOLD UNDERLINE "%c[Safe Console Inputs]" RESET, LINEFEED);
    NEWLINE;

    // 1. Integer Input
    int someInteger;
    getIntegerInput(&someInteger);
    NEWLINE;

    // 2. Mixed Integer & Character Input
    char someCharacter;
    getCharacterInput(&someInteger, &someCharacter);
    NEWLINE;

    // 3. Single Word Input
    char stringWithSize30[30];
    getWordInput(stringWithSize30);
    NEWLINE;

    // 4. Full Sentence Input
    getSentenceInput(stringWithSize30, sizeof(stringWithSize30));
    NEWLINE;

    return 0;
}

void clearInputBuffer() {
    while (1) {
        char cleanUp = getchar(); 
        if (cleanUp == '\n' || cleanUp == EOF) break; 
    }
}

void getIntegerInput(int *number) {
    printf("Type a number and press enter: ");
    scanf("%d", number);
    printf("The number entered is: " BOLD FG_GREEN "%d" RESET, *number);
    clearInputBuffer(); 
}

void getCharacterInput(int *number, char *character) {
    printf("Type a number and a character and press enter: %c", LINEFEED);
    scanf("%d %c", number, character);
    printf("The inputs entered are: integer = " BOLD FG_GREEN "%d" RESET " | character = " BOLD FG_GREEN "%c" RESET, *number, *character);
    clearInputBuffer();
}

void getWordInput(char string[]) {
    printf("Input a word: ");
    scanf("%29s", string);
    printf("The word inputted is: " BOLD FG_GREEN "%s" RESET, string);
    clearInputBuffer();
}

void getSentenceInput(char string[], int size) {
    printf("Input a sentence: ");
    fgets(string, size, stdin);

    string[strcspn(string, "\n")] = '\0';
    
    printf("The text inputted is: " BOLD FG_GREEN "%s" RESET, string);
}

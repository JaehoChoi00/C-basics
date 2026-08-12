#include <stdio.h>
#include <string.h>
#include "../variables/VariableConstants.h"

// Function Declaration

void functionName();
void functionWithParameters(char string[]);
char* functionWithReturn();
void functionWithStringManipulation(char string[]);

int main() {
    // Functions
    printf(BOLD UNDERLINE "%c[Functions]" RESET, LINEFEED);
    NEWLINE;
    functionName();
    NEWLINE;
    functionWithParameters("Parameter");
    NEWLINE;
    printf("Message from function: " BOLD FG_RED "%s" RESET, functionWithReturn());
    NEWLINE;
    char message[] = "Did you receive?";
    functionWithStringManipulation(message);
    printf("Sending Message " BOLD FG_GREEN "\"Did you receive?\"" RESET " to " BOLD "functionWithStringManipulation." RESET " New message: " BOLD FG_RED "\"%s\"" RESET, message);
    NEWLINE;

    return 0;
}

// Function Definition

void functionName() {
    printf("This is a function");
}

void functionWithParameters(char string[]) {
    printf("The is a function with a" BOLD FG_GREEN " %s" RESET, string);
}

char* functionWithReturn() {
    return "Message to Distribute";
}

void functionWithStringManipulation(char string[]) {
    strcpy(string, "Well received");
}
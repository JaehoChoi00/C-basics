#include <stdio.h>
#include <stdlib.h>
#include "Macros.h"

#include "../variables/VariableConstants.h"

int main(int argc, char *argv[]) {
    #ifdef DEBUG
        printf("%cThis is " BOLD FG_RED "DEBUG" RESET " mode%c", LINEFEED, LINEFEED);

    #endif

    #ifdef NORMAL
        printf("%cThis is " BOLD FG_COLOR(33) "NORMAL" RESET " mode%c", LINEFEED, LINEFEED);

        int a = 1;
        int b = 2;

        if (argc >= 3) {
            a = atoi(argv[1]);
            b = atoi(argv[2]);
        }
        printf("%d + %d = %d%c", a, b, ADD(a, b), LINEFEED);
        printf("%d - %d = %d%c", a, b, SUB(a, b), LINEFEED);
        printf("%d * %d = %d%c", a, b, MUL(a, b), LINEFEED);
        printf("%d / %d = %d%c", a, b, DIV(a, b), LINEFEED);
        printf("%d / %d = %lf%c%c", a, b, DIV_FLOAT(a, b), LINEFEED, LINEFEED);
        
    #endif
}
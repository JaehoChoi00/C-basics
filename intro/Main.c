#include <stdio.h>
#include <stdlib.h>
#include "../variables/VariableConstants.h"

int main(int argc, char *argv[]) {

    printf(BOLD "%cArguement count: [" RESET BOLD FG_GREEN UNDERLINE "%d" RESET BOLD"]%c" RESET, LINEFEED, argc, LINEFEED);

    printf(BOLD "%cArguement value for index [0]: [" RESET BOLD FG_GREEN UNDERLINE"%s" RESET BOLD "]%c" RESET, LINEFEED, argv[0], LINEFEED);

    printf("_____________________________________________%c", LINEFEED);

    printf("%cThe exact arguements written to run this:%c%c", LINEFEED, LINEFEED, LINEFEED);
    
    for (int index = 0; index < argc; index++) {
        printf(BOLD UNDERLINE FG_COLOR(50) "%s " RESET, argv[index]);
    }

    NEWLINE;

    return 0;
}
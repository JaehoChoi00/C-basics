#include <stdio.h>

#include "../variables/VariableConstants.h"

typedef enum {
    AUTOMATIC_ENUM_VALUE_ZERO,       
    AUTOMATIC_ENUM_VALUE_ONE,
    AUTOMATIC_ENUM_VALUE_TWO    
} AutomaticSequentialEnum;

typedef enum {
    EXPLICIT_STARTING_POINT_TEN = 10,
    AUTOMATIC_ENUM_VALUE_ELEVEN,
    AUTOMATIC_ENUM_VALUE_TWELVE
} EnumSequentialDriftExample;

typedef enum {
    EXPLICIT_ENUM_VALUE_TWO = 2,
    EXPLICIT_ENUM_VALUE_FOUR = 4,       
    EXPLICIT_ENUM_VALUE_SIX = 6,        
    EXPLICIT_ENUM_VALUE_EIGHT = 8   
} ExplicitCustomizedEnum;

int main(void) {
    printf(BOLD UNDERLINE "%c[C Enumerations]" RESET, LINEFEED);
    NEWLINE;

    AutomaticSequentialEnum sequentialEnumInstance = AUTOMATIC_ENUM_VALUE_ONE;
    printf("Default automatic sequential enum value (ZERO): " FG_GREEN "%d" RESET "%c", AUTOMATIC_ENUM_VALUE_ZERO, LINEFEED);
    printf("Default automatic sequential enum value (ONE): " FG_GREEN "%d" RESET, sequentialEnumInstance);
    NEWLINE;

    printf("Explicit starting point enum value (TEN): " FG_BLUE "%d" RESET "%c", EXPLICIT_STARTING_POINT_TEN, LINEFEED);
    printf("Automatic sequential drift enum value (ELEVEN): " FG_BLUE "%d" RESET, AUTOMATIC_ENUM_VALUE_ELEVEN);
    NEWLINE;

    ExplicitCustomizedEnum customizedEnumInstance = EXPLICIT_ENUM_VALUE_EIGHT;
    printf("Explicit customized discrete enum value (TWO): " FG_COLOR(50) "%d" RESET "%c", EXPLICIT_ENUM_VALUE_TWO, LINEFEED);
    printf("Explicit customized discrete enum value (EIGHT): " FG_COLOR(50) "%d" RESET, customizedEnumInstance);
    LINEBREAK;

    return 0;
}

#include <stdio.h>

#include "../variables/VariableConstants.h"

struct StructureWithTwoMembers {
    char characterMember;
    int integerMember;
};

struct StructureWithMemberRestrictions {
    unsigned int twoBitMember  : 2;
    unsigned int fourBitMember : 4; 
};

int main() {
    // Structures
    printf(BOLD UNDERLINE "%c[Structures]" RESET, LINEFEED);
    NEWLINE;

    struct StructureWithTwoMembers structureVariable1;

    structureVariable1.characterMember = 'A';
    structureVariable1.integerMember = 1;

    printf("structureVariable characterMember: " BOLD FG_GREEN "%c" RESET, structureVariable1.characterMember);
    NEWLINE;
    printf("structureVariable integerMember: " BOLD FG_GREEN "%d" RESET, structureVariable1.integerMember);
    NEWLINE;

    // Structures with restrictions
    printf(BOLD UNDERLINE "%c[Structures with restrictions]" RESET, LINEFEED);
    NEWLINE;

    struct StructureWithMemberRestrictions restrictedVariable;

    restrictedVariable.twoBitMember = 3;   
    restrictedVariable.fourBitMember = 12; 

    printf("restrictedVariable twoBitMember (2 bits): " BOLD FG_GREEN "%u" RESET, restrictedVariable.twoBitMember);
    NEWLINE;
    printf("restrictedVariable fourBitMember (4 bits): " BOLD FG_GREEN "%u" RESET, restrictedVariable.fourBitMember);
    NEWLINE;

    restrictedVariable.twoBitMember = 4;   

    printf("restrictedVariable OVERFLOW twoBitMember (Assigned 4, fits 2 bits): " BOLD FG_RED "%u" RESET, restrictedVariable.twoBitMember);
    NEWLINE;

    return 0;
}
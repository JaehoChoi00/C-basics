# Structures

[:arrow_left: Return to Main README](../README.md)

> This is a full rundown of the [Structures.c](/structures/Structures.c) file  
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/variables/   
> gcc Variables.c -o Variables && ./Variables  
> ```
> <br>

## Sections:

> * [`Structure With Two Members`](#structure-with-two-members)
> * [`Structure With Member Restrictions`](#structure-with-member-restrictions)

---

### [Structure With Two Members](#sections)

***Creation***

```c
struct StructureWithTwoMembers {
    char characterMember;
    int integerMember;
};
```

***C Syntax***

```c
struct StructureWithTwoMembers structureVariable1;

structureVariable1.characterMember = 'A';
structureVariable1.integerMember = 1;

printf("structureVariable characterMember: " BOLD FG_GREEN "%c" RESET, structureVariable1.characterMember);
NEWLINE;
printf("structureVariable integerMember: " BOLD FG_GREEN "%d" RESET, structureVariable1.integerMember);
NEWLINE;
```

***Output***

```txt
structureVariable characterMember: A

structureVariable integerMember: 1
```

### [Structure With Member Restrictions](#sections)

***Creation***

```c
struct StructureWithMemberRestrictions {
    unsigned int twoBitMember  : 2;  // Max value: 3 (2^2 - 1)
    unsigned int fourBitMember : 4;  // Max value: 15 (2^4 - 1)
};
```

***C Syntax***

```c
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
```

***Output***

```txt
restrictedVariable twoBitMember (2 bits): 3

restrictedVariable fourBitMember (4 bits): 12

restrictedVariable OVERFLOW twoBitMember (Assigned 4, fits 2 bits): 0
```
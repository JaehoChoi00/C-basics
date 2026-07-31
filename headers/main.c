#include <stdio.h>
#include "HeaderFiles.h" // Copies declarations so main knows the functions exist
#include "HeaderExperimentation.h"

int main(void) {
    
    someFunctionInHeaderFile(); 

    printf("1 + 1 = %d\n", add(1, 1));

    printf("1 - 1 = %d\n", sub(1, 1));

    printf("2 * 3 = %d\n", mul(2, 3));

    printf("2 / 3 = %d\n", div(2, 3));

    printf("2 %% 3 = %d\n", mod(2, 3));

    return 0;
}

// gcc main.c HeaderFiles.c HeaderExperimentation.c -o header_files

// Quickest way is gcc *.c -o header_files
/*
    This compiles every .c file in the folder you are in.
*/
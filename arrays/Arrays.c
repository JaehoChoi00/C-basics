#include <stdio.h>

int main() {
    // Character array = string
    char string[] = "This is a string.\n";
    printf("%s", string);
    
    // Integer array
    int integers[10]; // Array of 10 integers

    for (int i = 0; i < 10; i++) { 
        integers[i] = i; // Populate the array from 0 to 9
        printf("%d", integers[i]);
    }
    printf("\n");
    
    return 0;
}
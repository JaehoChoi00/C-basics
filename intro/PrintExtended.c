#include <stdio.h>

int main() {
    int count = 0; 

    // Counts how many characters have been printed before the %n specifier.
    printf("Hello%n World\n", &count); 
    
    // Outputs: Count is 5
    printf("Count is %d\n", count); 

    return 0;
}
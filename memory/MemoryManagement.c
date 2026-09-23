#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../variables/VariableConstants.h"

void demonstrateMalloc(int elementCount);
void demonstrateCalloc(int elementCount);
void demonstrateRealloc(void);

int main() {
    unsigned long sizeOfChar = sizeof(char);
    unsigned long sizeOfInt = sizeof(int);
    unsigned long sizeOfLong = sizeof(long);
    unsigned long sizeOfLongLong = sizeof(long long);
    unsigned long sizeOfFloat = sizeof(float);
    unsigned long sizeOfDouble = sizeof(double);

    unsigned long sizeOfIntPointer = sizeof(int *);
    unsigned long sizeOfVoidPointer = sizeof(void *);
    unsigned long sizeOfFnPointer = sizeof(void (*)(int));

    printf(BOLD UNDERLINE "%c[Dynamic Memory Management Demonstration]" RESET, LINEFEED);
    NEWLINE;

    printf(BOLD "System Types Size Diagnostics:" RESET "\n");
    printf("  char: %lu Byte | int: %lu Byte | long: %lu Byte | long long: %lu Byte\n", sizeOfChar, sizeOfInt, sizeOfLong, sizeOfLongLong);
    printf("  float: %lu Byte | double: %lu Byte\n", sizeOfFloat, sizeOfDouble);
    printf("  int*: %lu Byte | void*: %lu Byte | fn*: %lu Byte\n", sizeOfIntPointer, sizeOfVoidPointer, sizeOfFnPointer);
    NEWLINE;

    printf(BOLD UNDERLINE "%c[Dynamic Memory: malloc demo]" RESET, LINEFEED);
    NEWLINE;
    demonstrateMalloc(4);
    NEWLINE;

    printf(BOLD UNDERLINE "%c[Dynamic Memory: calloc demo]" RESET, LINEFEED);
    NEWLINE;
    demonstrateCalloc(4);
    NEWLINE;

    printf(BOLD UNDERLINE "%c[Dynamic Memory: realloc demo]" RESET, LINEFEED);
    NEWLINE;
    demonstrateRealloc();
    NEWLINE;

    return 0;
}

void demonstrateMalloc(int elementCount) {
    size_t sizeOfInt = sizeof(int);
    size_t total_bytes = elementCount * sizeOfInt;

    printf("[STAGE: ALLOCATION] Requesting %zu bytes for %d integers via malloc()...%c", total_bytes, elementCount, LINEFEED);

    int *ptr = (int *)malloc(total_bytes);

    if (ptr == NULL) {
        printf(FG_RED "[RESULT: FAILURE] Malloc Error: Out of Memory" RESET "\n");
        return;
    }

    printf("[RESULT: SUCCESS] Memory successfully allocated.%c", LINEFEED);
    printf("  -> Starting Base Memory Address (ptr): " BOLD FG_COLOR(190) "%p" RESET "%c", (void *)ptr, LINEFEED);
    printf("  -> Allocated Size: " BOLD FG_GREEN "%zu" RESET " bytes%c", total_bytes, LINEFEED);

    for (int i = 0; i < elementCount; i++) {
        ptr[i] = (i + 1) * 10;
        printf("  -> Element [%d] stored at Address " BOLD FG_COLOR(190) "%p" RESET " with Value: " FG_YELLOW "%d" RESET "%c", i, (void*)&ptr[i], ptr[i], LINEFEED);
    }

    printf("[STAGE: DEALLOCATION] Releasing memory block at Address " BOLD FG_COLOR(190) "%p" RESET "...%c", (void *)ptr, LINEFEED);
    free(ptr);
    
    ptr = NULL;
    printf("[RESULT: COMPLETED] Memory freed safely. Pointer reset to NULL (" BOLD FG_RED "%p" RESET ")", (void *)ptr);
}

void demonstrateCalloc(int elementCount) {
    size_t sizeOfInt = sizeof(int);

    printf("[STAGE: ALLOCATION] Requesting %d elements of size %zu bytes via calloc()...%c", elementCount, sizeOfInt, LINEFEED);

    int *ptr = (int *)calloc(elementCount, sizeOfInt);

    if (ptr == NULL) {
        printf(FG_RED "[RESULT: FAILURE] Calloc Error: Out of Memory" RESET "\n");
        return;
    }

    printf("[RESULT: SUCCESS] Memory allocated and cleared to zero automatically.%c", LINEFEED);
    printf("  -> Base Address (ptr): " BOLD FG_COLOR(190) "%p" RESET "%c", (void *)ptr, LINEFEED);

    printf("  Initial values right after calloc:\n");
    for (int i = 0; i < elementCount; i++) {
        printf("    Index [%d] | Address " BOLD FG_COLOR(190) "%p" RESET " | Initial Value: " FG_GREEN "%d" RESET "%c", i, (void*)&ptr[i], ptr[i], LINEFEED);
    }

    for (int i = 0; i < elementCount; i++) {
        ptr[i] = (i + 1) * 100;
    }

    printf("  Modified values after explicit assignment:\n");
    for (int i = 0; i < elementCount; i++) {
        printf("    Index [%d] | Address " BOLD FG_COLOR(190) "%p" RESET " | Updated Value: " FG_GREEN "%d" RESET "%c", i, (void*)&ptr[i], ptr[i], LINEFEED);
    }

    printf("[STAGE: DEALLOCATION] Freeing calloc block at Address " BOLD FG_COLOR(190) "%p" RESET "...%c", (void *)ptr, LINEFEED);
    free(ptr);
    ptr = NULL;
    printf("[RESULT: COMPLETED] Memory freed. Pointer set to NULL.");
}

void demonstrateRealloc(void) {
    size_t sizeOfInt = sizeof(int);
    int initialCount = 3;
    int expandedCount = 5;
    size_t initial_size = initialCount * sizeOfInt;
    size_t new_size = expandedCount * sizeOfInt;

    int *ptr = (int *)malloc(initial_size);
    if (ptr == NULL) return;

    for (int i = 0; i < initialCount; i++) {
        ptr[i] = i + 1;
    }

    printf("[STAGE: INITIAL STATE] Data stored at original address:%c", LINEFEED);
    printf("  -> Original Pointer Address (ptr): " BOLD FG_COLOR(190) "%p" RESET "%c", (void *)ptr, LINEFEED);
    for (int i = 0; i < initialCount; i++) {
        printf("    Index [%d] | Value: " FG_CYAN "%d" RESET "%c", i, ptr[i], LINEFEED);
    }

    printf("[STAGE: REALLOCATION] Resizing memory block from %d to %d elements (%zu bytes)...%c", 
            initialCount, expandedCount, new_size, LINEFEED);

    int *temp = (int *)realloc(ptr, new_size);
    if (temp == NULL) {
        printf(FG_RED "[RESULT: FAILURE] Realloc Error: Resizing Failed. Original memory block remains untouched." RESET "\n");
        free(ptr);
        return;
    }
    
    int *old_ptr = ptr;
    ptr = temp;

    printf("[RESULT: SUCCESS] Memory resized successfully.%c", LINEFEED);
    printf("  -> New Pointer Address (ptr): " BOLD FG_COLOR(190) "%p" RESET "%c", (void *)ptr, LINEFEED);
    
    if (old_ptr == ptr) {
        printf("  " BOLD FG_GREEN "NOTE: Memory was expanded 'In-Place' (The addresses match)." RESET "%c", LINEFEED);
    } else {
        printf("  " BOLD FG_RED "NOTE: Memory was moved to a 'New Location' due to hardware space restrictions." RESET "%c", LINEFEED);
    }

    for (int i = initialCount; i < expandedCount; i++) {
        ptr[i] = i + 1;
    }

    printf("  Expanded block state after successful realloc:\n");
    for (int i = 0; i < expandedCount; i++) {
        printf("    Index [%d] | Address " BOLD FG_COLOR(190) "%p" RESET " | Value: " FG_CYAN "%d" RESET "%c", i, (void*)&ptr[i], ptr[i], LINEFEED);
    }

    printf("[STAGE: DEALLOCATION] Releasing final reallocated block at Address " BOLD FG_COLOR(190) "%p" RESET "...%c", (void *)ptr, LINEFEED);
    free(ptr);
    ptr = NULL;
    printf("[RESULT: COMPLETED] Memory successfully swept. Pointer reset to NULL.");
}

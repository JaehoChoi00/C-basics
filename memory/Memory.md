# Memory

[:arrow_left: Return to Main README](../README.md)

> This is a full rundown of these files:
> * [`MemoryManagement.c`](/memory/MemoryManagement.c) 
> * [`PointersAddresses.c`](/memory/PointersAddresses.c) 
>
> ---
> 
> **Terminal code for compiling and running**:  
> ```bash
> cd C\ Basics/memory/   
> gcc MemoryManagement.c -o MemoryManagement && ./MemoryManagement  
> 
> gcc PointersAddresses.c -o PointersAddresses && ./PointersAddresses  
> ``` 
> <br>

## Sections:

> * [`Memory Management`](#memory-management)
> * [`Pointers & Addresses`](#pointers--addresses)

---

### [Memory Management](#sections)

> * [`Dynamic Memory: malloc demo`](#dynamic-memory-malloc-demo)
> * [`Dynamic Memory: calloc demo`](#dynamic-memory-calloc-demo)
> * [`Dynamic Memory: realloc demo`](#dynamic-memory-realloc-demo)

#### [Dynamic Memory: malloc demo](#memory-management)

***Creation***

```c
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

```

***Syntax C***

```c
demonstrateMalloc(4);
NEWLINE;

```

***Output***

```txt
[STAGE: ALLOCATION] Requesting 16 bytes for 4 integers via malloc()...
[RESULT: SUCCESS] Memory successfully allocated.
  -> Starting Base Memory Address (ptr): 0x153104080
  -> Allocated Size: 16 bytes
  -> Element [0] stored at Address 0x153104080 with Value: 10
  -> Element [1] stored at Address 0x153104084 with Value: 20
  -> Element [2] stored at Address 0x153104088 with Value: 30
  -> Element [3] stored at Address 0x15310408c with Value: 40
[STAGE: DEALLOCATION] Releasing memory block at Address 0x153104080...
[RESULT: COMPLETED] Memory freed safely. Pointer reset to NULL (0x0)

```

---

#### [Dynamic Memory: calloc demo](#memory-management)

***Creation***

```c
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

```

***Syntax C***

```c
demonstrateCalloc(4);
NEWLINE;

```

***Output***

```txt
[STAGE: ALLOCATION] Requesting 4 elements of size 4 bytes via calloc()...
[RESULT: SUCCESS] Memory allocated and cleared to zero automatically.
  -> Base Address (ptr): 0x151f059f0
  Initial values right after calloc:
    Index [0] | Address 0x151f059f0 | Initial Value: 0
    Index [1] | Address 0x151f059f4 | Initial Value: 0
    Index [2] | Address 0x151f059f8 | Initial Value: 0
    Index [3] | Address 0x151f059fc | Initial Value: 0
  Modified values after explicit assignment:
    Index [0] | Address 0x151f059f0 | Updated Value: 100
    Index [1] | Address 0x151f059f4 | Updated Value: 200
    Index [2] | Address 0x151f059f8 | Updated Value: 300
    Index [3] | Address 0x151f059fc | Updated Value: 400
[STAGE: DEALLOCATION] Freeing calloc block at Address 0x151f059f0...
[RESULT: COMPLETED] Memory freed. Pointer set to NULL.

```

---

#### [Dynamic Memory: realloc demo](#memory-management)

***Creation***

```c
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

```

***Syntax C***

```c
demonstrateRealloc();
NEWLINE;

```

***Output***

```txt
[STAGE: INITIAL STATE] Data stored at original address:
  -> Original Pointer Address (ptr): 0x153004270
    Index [0] | Value: 1
    Index [1] | Value: 2
    Index [2] | Value: 3
[STAGE: REALLOCATION] Resizing memory block from 3 to 5 elements (20 bytes)...
[RESULT: SUCCESS] Memory resized successfully.
  -> New Pointer Address (ptr): 0x153004270
  NOTE: Memory was expanded 'In-Place' (The addresses match).
  Expanded block state after successful realloc:
    Index [0] | Address 0x153004270 | Value: 1
    Index [1] | Address 0x153004274 | Value: 2
    Index [2] | Address 0x153004278 | Value: 3
    Index [3] | Address 0x15300427c | Value: 4
    Index [4] | Address 0x153004280 | Value: 5
[STAGE: DEALLOCATION] Releasing final reallocated block at Address 0x153004270...
[RESULT: COMPLETED] Memory successfully swept. Pointer reset to NULL.

```

---

### [Pointers & Addresses](#sections)

> * [`Addresses & Simple Pointers`](#addresses--simple-pointers)
> * [`Pointer Decay & Pass-By-Reference`](#pointer-decay--pass-by-reference)
> 
> 

#### [Addresses & Simple Pointers](#pointers--addresses)

***Syntax C***

```c
int originalValue = 64;

int *pointerToValue = &originalValue;

printf("Original value: (originalValue) = " BOLD FG_GREEN "%d" RESET "%c", originalValue, LINEFEED);
printf("Original value address: (&originalValue) = " BOLD FG_COLOR(190) "%p" RESET "%c", &originalValue, LINEFEED);
printf("Address stored as pointer: (pointerToValue) = " BOLD FG_COLOR(190) "%p" RESET "%c", pointerToValue, LINEFEED);
printf("Dereferenced pointer: (*pointerToValue) = " BOLD FG_RED "%d" RESET "%c", *pointerToValue, LINEFEED);
NEWLINE;

int archivedOriginal = *pointerToValue;
*pointerToValue = 99;
printf("Pointer value modified (*pointerToValue = 99): (archivedOriginal) = " BOLD FG_GREEN "%d" RESET " | (originalValue) = " BOLD FG_RED "%d" RESET "%c", archivedOriginal, originalValue, LINEFEED);
NEWLINE;

```

***Output***

```txt
Original value: (originalValue) = 64
Original value address: (&originalValue) = 0x16f0e28b8
Address stored as pointer: (pointerToValue) = 0x16f0e28b8
Dereferenced pointer: (*pointerToValue) = 64

Pointer value modified (*pointerToValue = 99): (archivedOriginal) = 64 | (originalValue) = 99

```

---

#### [Pointer Decay & Pass-By-Reference](#pointers--addresses)

***Creation***

```c
void passByReference(int *x) { *x = 999; }

void arrayDecay(int *arr) {
    printf("Size of array inside function scope using sizeof: " BOLD FG_RED "%lu" RESET " bytes (Decayed to pointer!)%c", sizeof(arr), LINEFEED);
}

void dummyFunction(int parameter) {
    printf("Executed dummyFunction via pointer (functionPointer(originalValue);). Received value: " BOLD FG_GREEN "%d" RESET "%c", parameter, LINEFEED);
}

```

***Syntax C***

```c
// Basic Type: Pure copy (Pass-By-Reference)
int testNum = 10;
printf("Before passByReference: " BOLD FG_GREEN "%d" RESET "%c", testNum, LINEFEED);
passByReference(&testNum);
printf("After passByReference (Changed): " BOLD FG_GREEN "%d" RESET "%c", testNum, LINEFEED);
NEWLINE;

// Array Type: Automatically decays into a pointer
int decayArray[5] = {10, 20, 30, 40, 50};
printf("Size of array in main scope using sizeof: " BOLD FG_RED "%lu" RESET " bytes%c", sizeof(decayArray), LINEFEED);

arrayDecay(decayArray);
NEWLINE;

void (*functionPointer)(int parameter) = dummyFunction;
printf("Address of dummyFunction using function name: " BOLD FG_COLOR(190) "%p" RESET "%c", (void *)dummyFunction, LINEFEED);
printf("Address stored in functionPointer: " BOLD FG_COLOR(190) "%p" RESET "%c", (void *)functionPointer, LINEFEED);

functionPointer(originalValue);
NEWLINE;

```

***Output***

```txt
Before passByReference: 10
After passByReference (Changed): 999

Size of array in main scope using sizeof: 20 bytes
Size of array inside function scope using sizeof: 8 bytes (Decayed to pointer!)

Address of dummyFunction using function name: 0x104938788
Address stored in functionPointer: 0x104938788Executed dummyFunction via pointer (functionPointer(originalValue);). Received value: 99

```

[:arrow_up: Return to Top](#memory)
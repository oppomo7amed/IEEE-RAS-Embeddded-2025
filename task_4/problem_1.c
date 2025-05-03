#include <stdio.h>

int main() {
    int intVar = 14;
    char charVar = 'O';
    float floatVar = 147.2004;
    long longVar = 1472004;

    int *intPtr;
    char *charPtr;
    float *floatPtr;
    long *longPtr;

    intPtr = &intVar;
    charPtr = &charVar;
    floatPtr = &floatVar;
    longPtr = &longVar;

    printf("\nUsing variables directly:\n");
    printf("Integer: value = %d, address = %p\n", intVar, &intVar);
    printf("Character: value = %c, address = %p\n", charVar, &charVar);
    printf("Float: value = %.2f, address = %p\n", floatVar, &floatVar);
    printf("Long: value = %ld, address = %p\n", longVar, &longVar);

    printf("\nUsing pointers:\n");
    printf("Integer: value = %d, address = %p\n", *intPtr, intPtr);
    printf("Character: value = %c, address = %p\n", *charPtr, charPtr);
    printf("Float: value = %.2f, address = %p\n", *floatPtr, floatPtr);
    printf("Long: value = %ld, address = %p\n", *longPtr, longPtr);

    // Changing values using pointers
    printf("\nModifying values using pointers:\n");
    *intPtr = 25;
    *charPtr = 'M';
    *floatPtr = 246.1974;
    *longPtr = 2561974;

    printf("New Integer: value = %d\n", intVar);
    printf("New Character: value = %c\n", charVar);
    printf("New Float: value = %.2f\n", floatVar);
    printf("New Long: value = %ld\n", longVar);

}
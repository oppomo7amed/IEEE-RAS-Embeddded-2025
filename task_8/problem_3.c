#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;

    // ---- 1. Allocate memory with malloc ----
    int *arr1 = (int *)malloc(5 * sizeof(int));
    if (arr1 == NULL) {
        printf("malloc failed!\n");
        return 1;
    }
    // Assign values
    for (i = 0; i < 5; i++) {
        arr1[i] = i + 1;   // values 1..5
    }
    printf("arr1 (malloc): ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n\n");

    // ---- 2. Allocate memory with calloc ----
    int *arr2 = (int *)calloc(5, sizeof(int));
    if (arr2 == NULL) {
        printf("calloc failed!\n");
        free(arr1);
        return 1;
    }
    // Assign values
    for (i = 0; i < 5; i++) {
        arr2[i] = (i + 1) * 10;   // values 10..50
    }
    printf("arr2 (calloc): ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");

    // ---- 3. Another malloc block ----
    int *arr3 = (int *)malloc(3 * sizeof(int));
    if (arr3 == NULL) {
        printf("malloc failed for arr3!\n");
        free(arr1);
        free(arr2);
        return 1;
    }
    // Assign values
    for (i = 0; i < 3; i++) {
        arr3[i] = (i + 1) * 100;   // values 100, 200, 300
    }
    printf("arr3 (malloc): ");
    for (i = 0; i < 3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n\n");

    // ---- 4. Reallocate arr3 to hold more values ----
    arr3 = (int *)realloc(arr3, 6 * sizeof(int));
    if (arr3 == NULL) {
        printf("realloc failed!\n");
        free(arr1);
        free(arr2);
        // arr3 is lost here, but original block is freed if realloc fails
        return 1;
    }
    // Assign new values for extended part
    for (i = 3; i < 6; i++) {
        arr3[i] = (i + 1) * 100;   // values 400, 500, 600
    }
    printf("arr3 (after realloc): ");
    for (i = 0; i < 6; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n\n");

    // ---- Free all memory ----
    free(arr1);
    free(arr2);
    free(arr3);

    printf("All memory freed successfully!\n");

    return 0;
}

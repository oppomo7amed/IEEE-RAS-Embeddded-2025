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

    // ---- 4. Free arr3 and allocate a bigger block ----
    free(arr3);  // old block released back to heap
    printf("arr3 memory freed.\n");

    int *arr4 = (int *)malloc(10 * sizeof(int));  // bigger block
    if (arr4 == NULL) {
        printf("malloc failed for arr4!\n");
        free(arr1);
        free(arr2);
        return 1;
    }
    // Assign values
    for (i = 0; i < 10; i++) {
        arr4[i] = (i + 1) * 1000;  // values 1000, 2000, ..., 10000
    }
    printf("arr4 (malloc - bigger block): ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr4[i]);
    }
    printf("\n\n");

    // ---- Free all memory ----
    free(arr1);
    free(arr2);
    free(arr4);

    printf("All memory freed successfully!\n");

    return 0;
}

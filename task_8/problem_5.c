#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, sum = 0;
    int *arr;

    // Ask user for number of elements
    printf("Enter number of integers: ");
    scanf("%d", &n);

    // Dynamically allocate memory
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if malloc fails
    }

    // Fill the array
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate sum
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Print result
    printf("Sum of all elements = %d\n", sum);

    // Free allocated memory
    free(arr);

    return 0;
}

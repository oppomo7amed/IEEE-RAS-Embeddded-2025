#include <stdio.h>
#include <stdlib.h>

// ----- Macros for controlling order -----
// Uncomment one of these to test
#define ASCENDING
// #define DESCENDING

// ----- Function Prototypes -----
int* sortAscending(int arr[], int n);
int* sortDescending(int arr[], int n);

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int* sorted;

    // ----- Decide which sorting function to call -----
    #ifdef ASCENDING
        sorted = sortAscending(arr, n);
        printf("\nSorted in Ascending order:\n");
    #endif

    #ifdef DESCENDING
        sorted = sortDescending(arr, n);
        printf("\nSorted in Descending order:\n");
    #endif

    for (i = 0; i < n; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    return 0;
}

// ----- Sort Ascending -----
int* sortAscending(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

// ----- Sort Descending -----
int* sortDescending(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

#include <stdio.h>

int CountOdd(int arr[], int *OddA, int *c, int s){
    int i = 0;
    for (int i=0 ; i<s ; i++){
        if (arr[i] % 2 != 0){
            OddA[*c] = arr[i];
            (*c)++;
        }
    }
}

int main(){
    int a[]= {1,2,3,4,5,6,7,8,9};
    int size = 9;
    int odda [100];
    int c = 0;
    int (*ptr)(int[], int*, int*, int) = CountOdd;

    ptr(a, odda, &c, size);

    printf("Odd numbers are: ");
    for(int i=0 ; i<c ; i++){
        printf("%d ", odda[i]);
    }
    printf("\nTotal odd numbers: %d", c);
}
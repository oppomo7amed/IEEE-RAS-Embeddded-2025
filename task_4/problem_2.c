#include <stdio.h>

int main(){
    int X , Y;
    int *XPtr, *YPtr;
    XPtr = &X, YPtr = &Y;
    
    printf("Enter two numbers: \nnum1: ");
    scanf("%d", &X);
    printf("num2: ");
    scanf("%d", &Y);

    printf("\nSum = %d \nDifference = %d \nProduct = %d \nQuotient = %d \n\n",(*XPtr + *YPtr),(*XPtr - *YPtr),(*XPtr * *YPtr),(*XPtr / *YPtr));
}
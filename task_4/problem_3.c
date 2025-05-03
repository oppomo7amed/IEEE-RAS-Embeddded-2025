#include <stdio.h>

int main(){
    int X, Y, temp;
    int *XPtr, *YPtr;
    XPtr = &X, YPtr = &Y;
    printf("Enter Two numbers to swap them :\na: ");
    scanf("%d",&X);
    printf("b: ");
    scanf("%d",&Y);
    temp = *XPtr;
    *XPtr = *YPtr;
    *YPtr = temp;
    printf("\na: %d \nb: %d", *XPtr, *YPtr);

}
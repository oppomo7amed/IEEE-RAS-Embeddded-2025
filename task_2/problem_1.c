#include <stdio.h>

int IsDivisible(int x,int y){
    if ( x%y == 0)
        return 1;
    else 
        return 0;
}

int main(){
    int x, y;

    printf("Enter the two integers to check if the first number is divisible by the second number\n");
    scanf("%d %d", &x, &y);

    if(y == 0) printf("Error: Division by zero is not allowed\n");

    else if(IsDivisible(x, y)) printf("%d is divisible by %d\n", x, y);

    else if(!IsDivisible(x, y)) printf("%d is not divisible by %d\n", x, y);
}
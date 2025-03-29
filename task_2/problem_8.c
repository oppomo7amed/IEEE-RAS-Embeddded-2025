#include<stdio.h>

int sequence(int x){
    if (x % 2 == 1) return 3*x + 1;
    else return x/2;
}

int main(){
    int x, i, c = 1;
    printf("Enter a number to give you the length of the 3n+1 sequence of it.\n");
    scanf("%d", &x);
    i = x;

    while( x != 1){
        x = sequence(x);
        c++;
    }

    printf("The length of 3n+1 sequence of %d : %d",i ,c);
}
#include<stdio.h>

int main(){
    int x;
    printf("Enter the final number\n");
    scanf("%d", &x);
    for (int i=1 ; i<=x ; i++){
        printf("%d\n", i);
    }
}
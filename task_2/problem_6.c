#include<stdio.h>

int F(int x){
    if (x == 1) return 0;
    if (x == 2) return 1;
    else return F(x-1) + F(x-2);
}

int main(){
    int n;
    printf("Enter a number between 1 and 30\n");
    scanf("%d",&n);

    printf("%d\n", F(n));
}
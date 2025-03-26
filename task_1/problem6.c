#include <stdio.h>

int main(){
    int x;
    printf("Enter the number that you wanna the divisors of it\n");
    scanf("%d",&x);

    for(int i = 1 ; i<=x ;i++){
        if (x % i == 0) printf("%d\n",i);
    }
}
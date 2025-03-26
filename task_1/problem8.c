#include <stdio.h>

int main(){
    int x;
    int sum = 0;
    int i; 
    int first = 1;

    printf("Enter the number that you wanna the divisors of it\n");
    scanf("%d",&x);

    printf("Sum : ");

    for(i = 1 ; i<x ;i++){
        if (x % i == 0){
            if (!first)
                printf("+ ");
            printf("%d ",i);
            sum += i;
            first = 0;
        } 
    }

    printf("= %d \n",sum);
    
    if (x == sum) printf("%d is a perfect number\n",x);
    if (x != sum) printf("%d isn't a perfect number\n",x);
}
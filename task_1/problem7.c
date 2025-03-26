#include <stdio.h>

int main(){
    int n;
    int p = 1;
    printf("Enter a positive integer less than 100 to check if the sum of its digits is a prime number or not \n");
    scanf("%d",&n);

    int newnum = n/10 + n%10 ;

    printf("%d\n",newnum);

    while(1){
        if (newnum == 2) {
            p = 1;
            break;
        }
        for(int i=2 ; i<newnum ; i++){
            if (newnum % i == 0){
                p = 0;
                break;
            }
        }
        break;
    }
    if (p == 1) printf("The sum of the digits of this number = %d is a prime number",n);
    if (p == 0) printf("The sum of the digits of this number = %d isn't a prime number",n);
}
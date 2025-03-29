#include<stdio.h>

void wonderful(int x){
    int a[100];
    int c = 0;

    if (x % 2 == 1){ //first of all check if it odd number or not
        
        //transfer from decimal to binary 
        while (x != 0){
            a[c] = x % 2;
            c++;
            x = x / 2;
        }

        //printing the binary to chick
        printf("binary = ");
        for (int i=0 ; i<c ; i++){
            printf("%d ", a[i]);
        }

        //checking if it palindrome number or not
        for (int i=0 ; i<=c/2 ; i++){
            if (a[i] != a[c-i-1]){
                printf("This number %d isn't a wonderful number\n", x);
                return;
            }
        }
        
        printf("This number is a wonderful number\n");
    }

    else 
        printf("This number isn't a wonderful number\n");
}

int main(){
    int x;
    printf("Enter the nuber you wanna check is it wonderdul or not\n");
    scanf("%d",&x);
    wonderful(x);
}
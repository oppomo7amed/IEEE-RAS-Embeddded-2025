#include<stdio.h>

int main(){
    printf("Enter the number of test cases then enter the numbers you wanna print the digits of it separated by a space.\n");
    
    //scanning the number of test cases
    int n;
    scanf("%d", &n);

    //scanning the numbers
    int a[n];
    for (int i=0 ; i<n ; i++){
        scanf("%d", &a[i]);
    }

    //printing it 
    for (int i=0 ; i<n ; i++){
        int x = a[i];
        int ra[10];
        int c = 0;
        while(x != 0){
            ra[c] = x % 10;
            x = x/10;
            c++;
            if (c > 10) break;
        }
        for (int j=c-1 ; j>=0 ; j--){
        printf("%d ", ra[j]);
        }
        printf("\n");
    }
}
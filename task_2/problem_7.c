#include<stdio.h>

int main(){
    int x, y;
    int a[20], b[20];
    int Ca = 0, Cb = 0;
    int GCD = 1;

    printf("Enter the two numbers\n");
    scanf("%d %d", &x, &y);
    
    //stor the divisor of the first num
    for (int i=1 ; i<=x ; i++){
        if (x % i == 0){
            a[Ca] = i;
            Ca++;
        }
    }

    //stor the divisor of the secound num
    for (int i=1 ; i<=y ; i++){
        if (y % i == 0){
            b[Cb] = i;
            Cb++;
        }
    }

    //serch for the Greatest Common Divisor
    for (int i=0 ; i<Ca ; i++){
        for (int j=0 ; j<Cb ; j++){
            if (a[i] == b[j] && a[i] > GCD)
            GCD = a[i];
        }
    }

    //print the output
    printf("GCD of %d and %d = %d", x, y, GCD);
}
#include<stdio.h>
#include<math.h>

void ArmstrongNumbers(int a ,int b){
    int n[10];
    static int f = 1;

    for (int i=a ; i<b ; i++){
        int j = i;
        int c = 0;
        double sum = 0;

        //stor numbers in array
        while (j != 0){
            if (c >= 10) break;
            n[c] = j%10;
            j = j/10;
            c++;
        }
        for (int v=0 ; v<c ; v++){
            sum += pow(n[v], c);
        }

        //printing the outputs
        if ( sum == i){
            if (!f) printf(", ");
            printf("%d",i);
            f = 0;
        }
    }
    printf(".\n");
}

int main(){
    int x, y;
    printf("Enter the numbers to give you all armstrong numbers between them\n");
    scanf("%d %d", &x, &y);
    ArmstrongNumbers(x,y);
}
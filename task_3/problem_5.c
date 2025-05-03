#include <stdio.h>
#include <stdlib.h>

int main(){
    int N ,pd = 0 ,sd = 0;
    printf("Enter the size of matrix U want :");
    scanf("%d", &N);

    int a[N][N];

    printf("Enter the variables and make sure that each variable between (-100 and 100) :\n");
    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<N ;j++){
            scanf("%d" , & a[i][j]);
        }
    }

    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<N ; j++){
            if (i == j){
                pd += a[i][j];
            }
        }
    }

    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<N ; j++){
            if (i + j == N - 1){
                sd += a[i][j];
            }
        }
    }

    int sum = abs(pd - sd);

    printf("\n The absolute summation of the primary and secondary diagonals = %d", sum);
}
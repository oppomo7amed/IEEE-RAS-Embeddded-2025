#include <stdio.h>

int main(){
    int N ,M;
    printf("Enter the size of matrix U want :");
    scanf("%d %d", &N ,&M);

    int a[N][M];

    printf("Enter the variables :\n");
    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<M ;j++){
            scanf("%d" , & a[i][j]);
        }
    }

    for (int i=0 ; i<N ; i++){
        for (int j=M-1 ; j>=0 ; j--){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

}
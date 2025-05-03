#include<stdio.h>

int main(){
    int r, c;
    printf("Enter the matrix size raw & column: ");
    scanf("%d %d", &r, &c);

    int a1[r][c], a2[r][c], sum[r][c];

    printf("Enter the first matrix variables: ");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            scanf("%d", &a1[i][j]);
        }
    }

    printf("Enter the second matrix variables: ");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            scanf("%d", &a2[i][j]);
        }
    }

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            sum[i][j] = a1[i][j] + a2[i][j];
        }
    }

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

}
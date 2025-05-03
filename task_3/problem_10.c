#include <stdio.h>

int main(){
    int N, sum = 0, f = 1;
    printf("Enter the size of the array : ");
    scanf("%d",&N);

    int a[N][N];
    printf("Enter the variables of the matrix :\n");
    for (int i = 0 ; i<N ; i++){
        for (int j = 0 ; j<N ; j++){
            scanf("%d",&a[i][j]);
        }
    }

    for (int j=0 ; j<N ;j++)
        sum += a[0][j];

    while(f){
        //for rows
        for (int i = 0 ; i<N ; i++){
            int r_sum = 0;
            for (int j = 0 ; j<N ; j++){
                r_sum += a[i][j];
            }
            if (sum != r_sum)
                f = 0;
        }

        //for columns
        for (int j = 0 ; j<N ; j++){
            int c_sum = 0;
            for (int i = 0 ; i<N ; i++){
                c_sum += a[i][j];
            }
            if (sum != c_sum)
                f = 0;
        }

        //for primary diagonal
        int pd_sum = 0;
        for (int i = 0 ; i<N ; i++){
            for (int j = 0 ; j<N ; j++){
                if (i == j){
                    pd_sum += a[i][j];
                }
            }
        }
        if (sum != pd_sum)
            f = 0;

        //for secondary diagonal
        int sd_sum = 0;
        for (int i = 0 ; i<N ; i++){
            for (int j = N ; j>=0 ; j--){
                if (i == j){
                    sd_sum += a[i][j];
                }
            }
        }
        if (sum != sd_sum)
            f = 0;
        break;
    }

    if (f == 1) printf("The square is a magic square.");
    else printf("The square is not a magic square.");
}
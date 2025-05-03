#include<stdio.h>

int main(){
    int N, X;

    printf("Enter the number of variables: ");
    scanf("%d",&N);

    int a[N];
    printf("Enter the variables to arrange it: ");
    for (int i=0 ; i<N ; i++){
        scanf("%d",&a[i]);
    }

    for (int i=0 ; i<N ; i++){
        int p = i, L = a[i];

        for (int j=i ; j<N ; j++){
            if (L > a[j]){
                L = a[j];
                p = j;
            }
        }
        a[p] = a[i];
        a[i] = L;
    }
    
    for(int i=0 ; i<N ; i++){
        printf("%d ", a[i]);
    }
    

}
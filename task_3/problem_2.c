#include<stdio.h>

int main(){
    int N, X;

    printf("Enter the number of variables: ");
    scanf("%d",&N);

    int a[N];
    printf("Enter the variables to give you the lowest number of them: ");
    for(int i=0 ; i<N ; i++){
        scanf("%d",&a[i]);
    }

    int s = 0, p = 1; 
    int L = a[s];

    while(s < N){
        if(L > a[s]){
            L = a[s];
            p = s+1;
        }
        s++;
    }
    printf("%d\n%d", L, p);

}
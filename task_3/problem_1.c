#include<stdio.h>

int main(){
    int N, X;

    printf("Enter the number of variables: ");
    scanf("%d",&N);

    int a[N];
    printf("Enter the variables: ");
    for(int i=0 ; i<N ; i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the number you wanna search for: ");
    scanf("%d",&X);

    int s = 0;
    while(s<N){
        if (X == a[s]){
            printf("%d",s);
            break;
        }
        s++;
    }
    if (s == N){
        printf("-1");
    }
}
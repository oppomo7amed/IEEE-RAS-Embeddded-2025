#include <stdio.h>

int main(){
    int N, c=0;

    printf("Enter the number of elements : ");
    scanf("%d", &N);

    int a[N];
    printf("Enter the elements \n");
    for (int i = 0 ; i<N ; i++){
        scanf("%d", &a[i]);
    }

    int min = a[0];
    for (int i = 1 ; i<N ; i++){
        if(a[i] < min){
            min = a[i];
        }
    }

    for (int i = 0 ; i<N ; i++){
        if (a[i] == min){
            c++;
        }
    }

    if (c % 2 == 1) printf("Lucky");
    else printf("Unlucky");
}

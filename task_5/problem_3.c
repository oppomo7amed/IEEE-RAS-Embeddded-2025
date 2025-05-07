#include <stdio.h>

int main(){
    int a[] = {10,-1,0,4,2,100,15,20,25,-5};

    int *ptr = a;
    for (int i=0 ; i<10 ; i++){
        for (int j=i+1 ; j<10 ; j++){
            if (*(ptr + i) > *(ptr +j)){
                int temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }

    printf("Array in ascending order:  ");
    for(int i=0 ; i<10 ; i++){
        printf("%d ",*(ptr + i));
    }
    
    for (int i=0 ; i<10 ; i++){
        for (int j=i+1 ; j<10 ; j++){
            if (*(ptr + i) < *(ptr +j)){
                int temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
    
    printf("\nArray in descending order: ");
    for(int i=0 ; i<10 ; i++){
        printf("%d ",*(ptr + i));
    }
}
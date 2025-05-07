#include <stdio.h>

int main(){
    int a1[3][3] = {{1,2,3},{4,5,6},{7,8,9}}, a2[3][3] = {{10,20,30},{40,50,60},{70,80,90}}, a[3][3];
    int (*ptr1)[3] = a1, (*ptr2)[3] = a2, (*ptr)[3] = a;
    
    for(int i=0 ; i<3 ; i++){
        for(int c=0 ; c<3 ; c++){
            int sum = 0;
            for(int j=0 ; j<3 ; j++){
                sum += ((*(*(ptr1 + i) + j)) * (*(*(ptr2 + j) + c)));
            }
            *(*(ptr + i) + c) = sum ;
        }
        
    }

    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ;j++){
            printf("%d ", *(*(ptr + i) + j));
        }
        printf("\n");
    }

}
#include <stdio.h>

int main(){
    int result = 1, num[4];

    for(int i=0;i<4;i++){
        scanf("%d",&num[i]);
        result = result*num[i] %100;
    }

    printf("Last two digits are: %02d",result); 
}
#include <stdio.h>

int main(){
    char a[] = "0123456789";
    int i = 0;
    while(a[i] != '\0'){
        if(a[i] % 2 == 0){
            printf("%c", a[i]);
        }
        i++;
    }
    printf("\n");

}
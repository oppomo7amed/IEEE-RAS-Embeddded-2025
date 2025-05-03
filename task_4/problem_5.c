#include <stdio.h>

int main(){
    char a[] = "Embedded Systems";
    int i = 0;
    while(a[i] != '\0'){
        i++;
    }
    printf("Length = %d", i);
}
#include <stdio.h>

int C2I(char *ptr){
    int result = 0;
    int sign = 1;

    if(*ptr == '-'){
        sign = -1;
        ptr++;
    }

    while(*ptr != '\0'){
        
        if (*ptr >= '0' && *ptr <= '9'){
            result = result * 10 + (*ptr - '0');
        }
        else break;
        ptr++;
    }
    return result;
}

int main(){
    char str1[] = "-70";
    char str2[] = "60";

    printf("%d\n", C2I(str1));
    printf("%d\n", C2I(str2));
}
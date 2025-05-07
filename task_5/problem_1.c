#include <stdio.h>

int com(char x[] , char y[]){ 
    int i = 0;
    while(x[i] != '\0' && y[i] != '\0'){
        if (x[i] != y[i]){
            return 0;
        }
        i++;
    }
    return (x[i] == '\0' && y[i] == '\0');
}

int main() {
    char s1[] = "RAS Chapter";
    char s2[] = "RAS Chapter";

    char *s1Ptr = s1;
    char *s2Ptr = s2;

    int (*comPtr)() = com;

    if (comPtr(s1Ptr , s2Ptr)) printf("Both strings are Identical");

    else printf("Strings aren't Identical");
}

#include <stdio.h>

void copy(char o[]){
    char c[50];
    int i = 0;
    while (o[i] != '\0'){
        c[i] = o[i];
        i++;
    }
    c[i] = '\0';
    
    printf("\nOriginal String: ");
    i = 0;
    while (o[i] != '\0'){
        printf("%c", o[i]);
        i++;
    }

    printf("\nCopied String: ");
    i = 0;
    while (c[i] != '\0'){
        printf("%c", c[i]);
        i++;
    } 
    printf("\n\n");
}

int main(){
    char Org[] = "Embedded systems";

    char *OrgPtr = Org;

    copy(OrgPtr);
}
#include <stdio.h>

int main(){
    char word[20];
    int c=0, check = 0;
    printf("Enter the word to check if it palindrome or not\n");
    scanf("%s", word);

    while (word[c] != '\0') c++;

    for (int i=0 ; i<c/2 ; i++){
        if (word[i] == word[c-1-i]){
            check = 1;
        }
        else{
            check = 0;
            printf("The word %s is not a palindrome.", word);
            break;
        }
    }
    if (check) printf("The word %s is a palindrome.", word);

}
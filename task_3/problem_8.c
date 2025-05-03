#include <stdio.h>
#include <ctype.h>

int main(){
    char S[1000000];

    printf("Enter the sentence to count the words :\n");
    fgets(S ,sizeof(S) ,stdin);

    int n_word = 0;
    int word = 0; //flag to chick if it word or not 

    for (int i = 0 ; S[i] != '\n' ; i++){
        
        if(isalpha(S[i])){
            if(!word){
                word = 1;
            }
        }
        else{
            if(word){
                word = 0;
                n_word++;
            }
        }
    }

    printf("The number of words = %d " , n_word);
}
# include<stdio.h>

int main(){
    int N;
    printf("Enter the number of characters : ");
    scanf("%d", &N);

    char a[N];

    printf("Enter the characters :\n");
    for (int i = 0 ; i<=N ; i++){
        scanf("%c",& a[i]);
    }

    int sum = 0;

    for (int i = 0 ; i<N ; i++){
        if (a[i] == a[i+1])
            sum ++;
    }
    
    int seq = N - sum;
    printf("The maximum subsequence = %d", seq);
}
#include<stdio.h>

int main(){
    int a[10][2];
    int r = 0;
    int sum = 0;

    printf("Enter two numbers to summation the sequence of numbers between them\n");

    while(1){
    int i, j;
    scanf("%d %d", &i, &j);
    
    if (i <= 0 || j <= 0) break;

    a[r][0] = i;
    a[r][1] = j;
    r++;
    
    if (r>=10) break;
    }

    for(int i=0 ; i < r ;i++){
        int s = (a[i][0] < a[i][1]) ? a[i][0] : a[i][1];
        int e = (a[i][0] > a[i][1]) ? a[i][0] : a[i][1];
        
        for(int j=s; j<=e ;j++){
            sum += j;
            printf("%d ",j);
            if (j < e){
                printf("+ ");
            }
        }
        printf("= %d\n",sum);
        sum = 0;
    }
}
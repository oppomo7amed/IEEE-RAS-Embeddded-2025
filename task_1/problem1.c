#include <stdio.h>

int main()
{
    int n, BigBoss = 0, CuteOne = 99999999;
    printf("Enter the varliables, Please!, and if you wanna stop enter(-1) \n");

    while(1) {

    scanf("%d",&n);
    
    if (n == -1) break;
    
    if (n > BigBoss) BigBoss = n;
    if (n < CuteOne) CuteOne = n;
    }
    printf("Largest number = %d ,and the smallest one = %d\n",BigBoss,CuteOne);
}
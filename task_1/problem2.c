#include <stdio.h>

int main()
{
    int A, Y,M,D;
    printf("I'm gonna make a magic for you tell me your age in days and I'll give it back to you in \"Years,Months,Days\" form\n");

    scanf("%d", &A);
    Y = A/365;
    A = A - Y*365;
    M = A/30;
    A = A - M*30;
    D = A;

    printf("Abracadabra, You ara %d years, %d months and %d days old \n",Y,M,D);
}
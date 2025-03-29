#include<stdio.h>

int reach(int base, int n){
    if (n == base) return 1;

    if (n%10 != 0 && n%20 != 0) return 0;

    if (n%10 == 0 && reach(base, n/10)) return 1;

    if (n%20 == 0 && reach(base, n/20)) return 1;
}

int main(){
    printf("Enter the number of test cases then enter the numbers you wanna check it.\n");
    
    //scanning the number of test cases
    int n;
    scanf("%d", &n);

    //scanning the numbers
    int a[n];
    for (int i=0 ; i<n ; i++){
        scanf("%d", &a[i]);
    }
    
    //check if the number can reach the base or not
    for (int i=0 ; i<n ; i++){
        if ( reach(a[0], a[i]) ) printf("YES\n");
        if ( !reach(a[0], a[i]) ) printf("NO\n");
    }
}
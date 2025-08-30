#include <stdio.h>

// ----- Macro Definitions -----
#define ADD(x, y)    ((x) + (y))
#define SUB(x, y)    ((x) - (y))

// ----- Control Macro -----
// Uncomment one to test
#define DO_ADD
// #define DO_SUB

int main() {
    int a, b, result;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // ----- Switch between operations -----
    #ifdef DO_ADD
        result = ADD(a, b);
        printf("Result (Addition): %d\n", result);
    #endif

    #ifdef DO_SUB
        result = SUB(a, b);
        printf("Result (Subtraction): %d\n", result);
    #endif

    return 0;
}

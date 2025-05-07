#include <stdio.h>

int Add (int a, int b){
    return a + b;
}

int Subtract (int a, int b){
    return a - b;
}

int Multiply (int a, int b){
    return a * b;
}

int Divide (int a, int b){
    return a / b;
}

int main(){
    int choice, x, y;
    printf("Select an operation:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\nEnter your choice: ");
    scanf("%d",&choice);
    printf("Enter two numbers :");
    scanf("%d%d", &x, &y);


    switch(choice){
        case 1:
            printf("Result: %d", Add(x,y));
            break;
        case 2:
            printf("Result: %d", Subtract(x,y));
            break;
        case 3:
            printf("Result: %d", Multiply(x,y));
            break;
        case 4:
            if (y == 0){
                printf("Error, can't divide by zero");
                break;
            }
            printf("Result: %d", Divide(x,y));
            break;
        default:
            printf("Your choice isn't available");
            break;
    }
}
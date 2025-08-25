#include <stdio.h>

typedef enum {
    OP_PLUS  = '+',
    OP_MINUS = '-',
    OP_MUL   = '*',
    OP_DIV   = '/',
    OP_AND   = '&',
    OP_OR    = '|',
    OP_NOT   = '!'
} t_operation;

void calculate(int operand1, int operand2, char op) {
    switch ((t_operation)op) {
        case OP_PLUS:
            printf("Result: %d\n", operand1 + operand2);
            break;
        case OP_MINUS:
            printf("Result: %d\n", operand1 - operand2);
            break;
        case OP_MUL:
            printf("Result: %d\n", operand1 * operand2);
            break;
        case OP_DIV:
            if (operand2 != 0)
                printf("Result: %d\n", operand1 / operand2);
            else
                printf("Error: Division by zero!\n");
            break;
        case OP_AND:
            printf("Result: %d\n", operand1 & operand2);
            break;
        case OP_OR:
            printf("Result: %d\n", operand1 | operand2);
            break;
        case OP_NOT:
            printf("Result: %d\n", !operand1); // unary, ignores operand2
            break;
        default:
            printf("Error: Invalid operation '%c'\n", op);
    }
}

int main() {
    int a, b;
    char op;

    printf("Enter expression (e.g., 5 3 +): ");
    scanf("%d %d %c", &a, &b, &op);

    calculate(a, b, op);

    return 0;
}

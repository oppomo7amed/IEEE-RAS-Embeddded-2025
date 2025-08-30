#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

void push(Stack* s, int value) {
    s->arr[++s->top] = value;
}

void printStack(Stack* s) {
    printf("Stack (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

void swapTopTwo(Stack* s) {
    if (s->top < 1) {
        printf("Not enough elements to swap!\n");
        return;
    }
    int temp = s->arr[s->top];
    s->arr[s->top] = s->arr[s->top - 1];
    s->arr[s->top - 1] = temp;
}

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Before swap:\n");
    printStack(&s);

    swapTopTwo(&s);

    printf("After swap:\n");
    printStack(&s);

    return 0;
}

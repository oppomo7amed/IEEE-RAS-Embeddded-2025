#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue {
    char arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->rear < q->front;
}

void enqueue(Queue* q, char value) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow!\n");
        return;
    }
    q->arr[++q->rear] = value;
}

char dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow!\n");
        return '\0';
    }
    return q->arr[q->front++];
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');

    char removed = dequeue(&q);
    printf("Dequeued value: %c\n", removed);

    return 0;
}

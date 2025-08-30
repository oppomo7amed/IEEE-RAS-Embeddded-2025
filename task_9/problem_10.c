#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // small size to test easily

typedef struct Queue {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->rear < q->front;
}

int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is FULL! Cannot enqueue %d\n", value);
        return;
    }
    q->arr[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY! Cannot dequeue\n");
        return -1;
    }
    return q->arr[q->front++];
}

int getFront(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY! No front value\n");
        return -1;
    }
    return q->arr[q->front];
}

int getRear(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY! No rear value\n");
        return -1;
    }
    return q->arr[q->rear];
}

int main() {
    Queue q;
    initQueue(&q);

    printf("Is queue empty? %s\n", isEmpty(&q) ? "Yes" : "No");

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front: %d\n", getFront(&q));
    printf("Rear: %d\n", getRear(&q));

    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Is queue full? %s\n", isFull(&q) ? "Yes" : "No");

    dequeue(&q);
    printf("After one dequeue, Front: %d\n", getFront(&q));

    return 0;
}

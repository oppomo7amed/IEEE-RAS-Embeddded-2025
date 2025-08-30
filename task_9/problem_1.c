#include <stdio.h>
#include <stdlib.h>

// Node structure (train wagon)
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print list and length
void printList(Node* head) {
    int length = 0;
    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        length++;
    }
    printf("NULL\nLength: %d\n", length);
}

int main() {
    // Create first train manually
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    // Print list
    printList(head);

    return 0;
}

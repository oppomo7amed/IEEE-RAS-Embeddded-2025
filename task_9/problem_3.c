#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to get value at a given position
int getValueAt(Node* head, int position) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (count == position)
            return temp->data;
        count++;
        temp = temp->next;
    }
    return -1; // not found
}

// Function to insert a node at a specific position
void insertAtPosition(Node** head, int value, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (position == 0) {  // insert at head
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return; // position is greater than length

    newNode->next = temp->next;
    temp->next = newNode;
}

// Helper function to print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertAtPosition(&head, 10, 0);
    insertAtPosition(&head, 20, 1);
    insertAtPosition(&head, 30, 2);

    printList(head);

    printf("Value at position 1: %d\n", getValueAt(head, 1));

    insertAtPosition(&head, 15, 1);
    printList(head);

    return 0;
}

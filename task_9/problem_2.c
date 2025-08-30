#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert at the end
void insertAtEnd(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert at the beginning
void insertAtBeginning(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node by value
void deleteNode(Node** head, int value) {
    if (*head == NULL) return;

    Node* temp = *head;
    Node* prev = NULL;

    // If the head itself holds the value
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the node to delete
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;  // Value not found

    prev->next = temp->next;
    free(temp);
}

// Helper function to print list
void printList(Node* head) {
    Node* temp = head;
    int length = 0;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        length++;
    }
    printf("NULL\nLength: %d\n", length);
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printList(head);

    insertAtBeginning(&head, 5);
    printList(head);

    deleteNode(&head, 20);
    printList(head);

    return 0;
}

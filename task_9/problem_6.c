#include <stdio.h>
#include <stdlib.h>

// Circular linked list node
typedef struct CNode {
    int data;
    struct CNode* next;
} CNode;

// Insert at a specific position (1-based index)
void insertAtPosition(CNode** head, int value, int position) {
    CNode* newNode = (CNode*)malloc(sizeof(CNode));
    newNode->data = value;

    if (*head == NULL) { // first node
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    if (position == 1) { // insert at head
        CNode* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
        return;
    }

    // Insert somewhere else
    CNode* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Print circular list
void printCircularList(CNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    CNode* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head: %d)\n", head->data);
}

int main() {
    CNode* head = NULL;

    insertAtPosition(&head, 10, 1); // first node
    insertAtPosition(&head, 20, 2); // at end
    insertAtPosition(&head, 30, 2); // middle
    insertAtPosition(&head, 5, 1);  // new head

    printf("Circular Linked List:\n");
    printCircularList(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node at the end of the list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    return head;
}

// Function to reverse the doubly linked list
struct Node* reverseList(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

// Function to display the content of the list
void displayList(struct Node* head) {
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the end of the list
    for (int i = 1; i <= 5; i++) {
        head = insertEnd(head, i * 10);
    }

    // Display the list before reversing
    printf("Before Reversal:\n");
    displayList(head);

    // Reverse the list
    head = reverseList(head);

    // Display the list after reversing
    printf("After Reversal:\n");
    displayList(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to insert a node at a specific position
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (head == NULL || position == 0) {
        return insertAtBeginning(head, data);
    }
    struct Node* current = head;
    int count = 1;
    while (current->next != NULL && count < position) {
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    return head;
}

// Function to count the number of nodes and display data
void countAndDisplay(struct Node* head) {
    struct Node* current = head;
    int count = 0;

    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        count++;
        current = current->next;
    }
    printf("NULL\n");

    printf("Number of nodes: %d\n", count);
}

// Function to delete a node at the beginning
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* newHead = head->next;
    if (newHead != NULL) {
        newHead->prev = NULL;
    }
    free(head);
    return newHead;
}

// Function to delete a node at the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

// Function to delete a node at a specific position
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        return NULL;
    }
    if (position == 0) {
        return deleteAtBeginning(head);
    }
    struct Node* current = head;
    int count = 0;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        return head; // No node found at the given position
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    free(current);
    return head;
}

int main() {
    struct Node* head = NULL;

    // Insert at the beginning
    head = insertAtBeginning(head, 10);

    // Insert at the end
    head = insertAtEnd(head, 20);

    // Insert at a specific position (position 1)
    head = insertAtPosition(head, 15, 1);

    // Display the list and count the nodes
    countAndDisplay(head);

    // Delete at the beginning
    head = deleteAtBeginning(head);

    // Delete at the end
    head = deleteAtEnd(head);

    // Delete at a specific position (position 0)
    head = deleteAtPosition(head, 0);

    // Display the list and count the nodes after deletions
    countAndDisplay(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a node at the end of the linked list
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

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to remove the last node and insert it at the beginning
void removeLastInsertBeginning(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("Only one or no node in the list, no operation possible.\n");
        return;
    }

    Node *temp = *head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    temp->next = *head;
    *head = temp;

    printf("Last node removed and inserted at the beginning.\n");
}

int main() {
    Node* head = NULL;
    int value;

    printf("Enter the number of elements: ");
    int count;
    scanf("%d", &count);

    printf("Enter %d elements: ", count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    printf("Original List: ");
    displayList(head);

    removeLastInsertBeginning(&head);

    printf("List after removing the last node and inserting at the beginning: ");
    displayList(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Node structure for singly linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void createLinkedList() {
    int value;
    char ch;

    do {
        printf("Enter the value for the node: ");
        scanf("%d", &value);

        Node *newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}

void displayLinkedList() {
    Node *temp = head;
    if (temp == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void searchNode(int key) {
    Node *temp = head;
    int pos = 1;
    int found = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Node found at position: %d\n", pos);
            found = 1;
        }
        temp = temp->next;
        pos++;
    }

    if (found == 0) {
        printf("Node not found in the Linked List.\n");
    }
}

void insertLastPosition(int value) {
    Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node with value %d inserted at the last position.\n", value);
}

int main() {
    int choice, key, value;

    do {
        printf("\nMenu:\n");
        printf("1. Create linked list\n");
        printf("2. Display linked list\n");
        printf("3. Search node\n");
        printf("4. Insert at last position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createLinkedList();
                break;
            case 2:
                displayLinkedList();
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &key);
                searchNode(key);
                break;
            case 4:
                printf("Enter the value to insert at last position: ");
                scanf("%d", &value);
                insertLastPosition(value);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

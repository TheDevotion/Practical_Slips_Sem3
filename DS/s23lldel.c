#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);

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

// Function to delete a node at a specific position from the linked list
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = *head;

    if (position == 1) {
        *head = temp->next;
        free(temp);
        printf("Node at position %d deleted.\n", position);
        return;
    }

    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Node at position %d doesn't exist.\n", position);
        return;
    }

    Node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
    printf("Node at position %d deleted.\n", position);
}

int main() {
    Node* head = NULL;
    int choice, value, position;

    do {
        printf("\nLinked List Operations\n");
        printf("1. Create linked list\n");
        printf("2. Display linked list\n");
        printf("3. Insert at the last position\n");
        printf("4. Delete from a specific position\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                int n;
                scanf("%d", &n);
                printf("Enter the elements: ");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &value);
                    insertAtEnd(&head, value);
                }
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 4:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (1);

    return 0;
}

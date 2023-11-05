#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Node structure for a singly linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to count the total number of nodes in the linked list
int countNodes(Node *head) {
    int count = 0;
    Node *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Function to display the linked list and count the total number of nodes
void displayList(Node *head) {
    Node *current = head;

    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    int totalNodes = countNodes(head);
    printf("Total number of nodes: %d\n", totalNodes);
}

int main() {
    Node *head = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter data for each node:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        if (head == NULL) {
            head = createNode(data);
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = createNode(data);
        }
    }

    displayList(head);
    getch();

    return 0;
}

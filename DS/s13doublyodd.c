#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Doubly linked list node structure
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayOddNodes(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;
    printf("Nodes with odd values: ");
    while (current != NULL) {
        if (current->data % 2 != 0) {
            printf("%d ", current->data);
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int n, data;

    printf("Enter the number of nodes in the list: ");
    scanf("%d", &n);

    printf("Enter the data for each node:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        Node *newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    printf("Doubly Linked List created.\n");

    displayOddNodes(head);

    getch();
    return 0;
}

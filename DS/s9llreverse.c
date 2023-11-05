#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

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

Node* insertEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

Node* reverseList(Node* head) {
    Node *prev, *current, *nextNode;
    prev = NULL;
    current = head;
    
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
    return head;
}

void displayList(Node* head) {
    Node* temp = head;

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter data for each node:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("\nOriginal list:\n");
    displayList(head);

    head = reverseList(head);

    printf("\nReversed list:\n");
    displayList(head);

    getch();
    return 0;
}

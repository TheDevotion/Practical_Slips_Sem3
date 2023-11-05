#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a node at the end of the linked list
void insert(Node** head, int value) {
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

// Function to swap mth and nth elements of a singly linked list
void swapNodes(Node** head, int m, int n) {
    if (m == n) {
        // Nodes are same, no need to swap
        return;
    }

    Node *temp = *head, *nodeM = NULL, *nodeN = NULL, *prevM = NULL, *prevN = NULL;

    // Find nodeM, nodeN and their previous nodes
    while (temp != NULL) {
        if (temp->data == m) {
            nodeM = temp;
        } else if (temp->data == n) {
            nodeN = temp;
        }

        if (nodeM == NULL) {
            prevM = temp;
        }

        if (nodeN == NULL) {
            prevN = temp;
        }

        temp = temp->next;
    }

    if (nodeM == NULL || nodeN == NULL) {
        printf("Nodes not found.\n");
        return;
    }

    // If m is head node
    if (prevM != NULL) {
        prevM->next = nodeN;
    } else {
        *head = nodeN;
    }

    // If n is head node
    if (prevN != NULL) {
        prevN->next = nodeM;
    } else {
        *head = nodeM;
    }

    // Swap next pointers
    temp = nodeM->next;
    nodeM->next = nodeN->next;
    nodeN->next = temp;
}

// Function to print the linked list
void display(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int value, m, n, i, count;

    printf("Enter the number of elements: ");
    scanf("%d", &count);

    printf("Enter %d elements: ", count);
    for (i = 0; i < count; i++) {
        scanf("%d", &value);
        insert(&head, value);
    }

    printf("Enter the positions (m and n) to swap: ");
    scanf("%d %d", &m, &n);

    printf("Original List: ");
    display(head);

    swapNodes(&head, m, n);

    printf("List after swapping %d and %d: ", m, n);
    display(head);

    return 0;
}

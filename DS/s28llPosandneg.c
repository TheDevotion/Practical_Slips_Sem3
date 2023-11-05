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

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* positiveList = NULL;
    Node* negativeList = NULL;
    int n, num;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &num);

        if (num >= 0) {
            insertAtEnd(&positiveList, num);
        } else {
            insertAtEnd(&negativeList, num);
        }
    }

    printf("\nList of Positive Numbers: ");
    displayList(positiveList);

    printf("\nList of Negative Numbers: ");
    displayList(negativeList);

    return 0;
}

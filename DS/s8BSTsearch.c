#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void display(Node *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

Node* search(Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return search(root->right, key);

    return search(root->left, key);
}

int main() {
    Node *root = NULL;
    int choice, data, key;
    Node *searchResult;

    do {
        clrscr();
        printf("Menu:\n");
        printf("1. Create a Binary Search Tree\n");
        printf("2. Display\n");
        printf("3. Search an element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Data inserted successfully!");
                getch();
                break;

            case 2:
                printf("Binary Search Tree elements: ");
                display(root);
                getch();
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);
                searchResult = search(root, key);
                if (searchResult != NULL)
                    printf("Element found in the Binary Search Tree!");
                else
                    printf("Element not found in the Binary Search Tree.");
                getch();
                break;

            case 4:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice. Please try again.");
                getch();
        }
    } while (choice != 4);

    return 0;
}

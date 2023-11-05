#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Structure defining the Binary Search Tree node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node and return its pointer
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the Binary Search Tree
Node *insert(Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to display the Binary Search Tree elements in ascending order
void display(Node *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

// Function to find the node with the minimum value in the Binary Search Tree
Node *findMin(Node *node) {
    Node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node with a specified value from the Binary Search Tree
Node *deleteNode(Node *root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node *root = NULL;
    int choice, data;

    do {
        clrscr();
        printf("Menu:\n");
        printf("1. Create a Binary Search Tree\n");
        printf("2. Display\n");
        printf("3. Delete an element\n");
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
                printf("Enter element to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Element deleted successfully!");
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

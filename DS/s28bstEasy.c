#include <stdio.h>
#include <stdlib.h>

// Check easy starting wala.

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert into BST\n");
        printf("2. Search a node\n");
        printf("3. Display BST using Post Order Traversal\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                Node* found = search(root, value);
                if (found != NULL) {
                    printf("%d is found in the BST.\n", value);
                } else {
                    printf("%d is not found in the BST.\n", value);
                }
                break;

            case 3:
                printf("Post Order Traversal of the BST: ");
                postOrderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (1);

    return 0;
}

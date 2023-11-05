#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int treeDegree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDegree = treeDegree(root->left);
    int rightDegree = treeDegree(root->right);
    return 1 + max(leftDegree, rightDegree);
}

int countLeafNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    int n, value;

    Node* root = NULL;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    printf("Enter the integers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Number of nodes in the tree: %d\n", countNodes(root));
    printf("Degree of the tree: %d\n", treeDegree(root));
    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    getch();
    return 0;
}


/*menu driven program using C for BST and menu include:
1. Create a binary search tree
2.Insert Element in a BST
3. Display.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// defining the structure of node of a BST.
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;

// creating a Node.

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}
// Inserting a node

Node* insert(Node* root, int data) {
	// base case.
	if(root == NULL) {
		return createNode(data);
	}

	// This is a recursive function call
	if(data <= root -> data) {
		root -> left = insert(root -> left, data);
	}
	else if ( data >= root -> data) {
		root -> right = insert(root -> right, data);
	}
	return root;
}

// display bst using inorder Traversal

void display(Node* root) {
	if(root == NULL){
		return;
	}
	display(root -> left);
	printf(" %d ", root -> data);
	display(root -> right);
}

void main () {
	Node* root = NULL;
	int choice,data;
	char ans;
	clrscr();

	// menu driven:
	do{

		printf("----C program for Binary Search Tree----\n");
		printf("1.Create a BST\n");
		printf("2.Insert an element in BST\n");
		printf("3.Display BST\n");
		scanf("%d", & choice);

	switch(choice) {
		case 1 :printf("Give data to create a BST.\n");
			scanf("%d", & data);
			root = createNode(data);
			printf("A Binary Search Tree Has been created with root value %d.\n",data);
			break;

		case 2 : printf("Enter the value to insert in the BST:\n");
			scanf("%d", & data);
			root = insert(root,data);
			printf("Value %d has been inserted in the BST\n",data);
			break;
		case 3 :
			printf("\nBinary Search Tree elements (in order traversal) :\n");
			if(root == NULL) {
				printf("Tree is empty\n");
			}else {
				display(root);
			}
			break;
		default:printf("Invalid Choice\n");
			break;
	}


	 printf("\nDo you want to continue(Y/N) ?: ");
	 scanf(" %c", & ans);
	}while(ans == 'Y' || ans == 'y');


	getch();

}







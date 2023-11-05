/*
Write a menu driven program using C for binary search tree.
The menu includes
-Create a binary search tree
-Traverse it by using Inorder and preorder traversing technique
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* right;
	struct Node* left;
}Node;
Node* createNode(int data) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;

	return newNode;
}

Node* insertNode(Node* root, int data) {

	if(root == NULL) {
		return createNode(data);
	}
	else if( data <= root -> data) {
		root -> left = insertNode(root -> left, data);
	}
	else {
		root -> right = insertNode(root -> right, data);
	}
	return root;
}




void inOrder(Node* root) {

	if(root == NULL) {
		return;
	}

	inOrder(root->left);
	printf("%d ",root->data);
	inOrder(root->right);
}

void preOrder(Node* root) {

	if(root == NULL) {
		return;
	}

	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}



void main(){
	int choice,n,data,i;
	char ans;

       Node* root = NULL;
       clrscr();


       do{
		printf("---Binary Search Tree---\n");
		printf("1.Create BST\n");
		printf("2.Inorder traversal.\n");
		printf("3.Preorder traversal.\n");
		scanf("%d", & choice);

	switch(choice) {

		case 1:
			printf("How many nodes you want to insert in your BST?\n");
			scanf("%d",&n);
			printf("Insert nodes:\n");
			for(i=0; i<n; i++) {
				scanf("%d",&data);
				root = insertNode(root,data);
			}
			break;
		case 2:
			printf("Inorder traversal of BST:\n");
			inOrder(root);
			break;

		case 3:
			printf("PreOrder traverasal of BST\n");
			preOrder(root);
			break;


		default:printf("Invalid entry!\n");
			break;
		}

		printf("\nDo you want to continue(y/n)? :");
		scanf(" %c",&ans);
	}while(ans == 'y' || ans == 'Y');

	getch();
}
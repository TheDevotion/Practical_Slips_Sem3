/*
menu driven BST
1.Create
2.Display.
3. delete a given element from BST.
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode -> data = data;
	newNode -> left = NULL;
	newNode -> right = NULL;

	return newNode;
}

Node * insertNode(Node* root, int data) {
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
void deleteNode(Node* root,int kill){
	// travers the BST.
	if(root == NULL) {
		return;
	}
	delete(root->left,kill);
	if(root -> data == kill) {
		// code for deleting node
	}
	delete(root ->right, kill);
}

void display(Node* root) {
	// using inorder traversal:

	if(root == NULL) {
		return;
	}

	display(root -> left);
	printf("%d\t", root -> data);
	display(root -> right);

}

void main(){
	Node* root = NULL;
	int n,i,choice,data,kill;
	char ans;
	clrscr();



	do{
		printf("--Operations on BST--");
		printf("1.Create a BST\n");
		printf("2.Display the BST\n");
		printf("3.Delete an element from BST\n");

		printf("Enter your choice: ");
		scanf("%d", & choice);

	switch(choice){
		case 1:
			printf("How many nodes you want in your BST?\n");
			scanf("%d",&n);
			printf("Enter nodes:\n");
			for(i=0; i<n; i++) {
				scanf("%d", &data);
				root = insertNode(root,data);
			}
			printf("\nYour BST is created !\n");
			break;
		case 2:
			printf("Your BST is: (inorder traversal) :\n\n");
			display(root);
			break;
		case 3:
			printf("Which element you want to delete?\n");
			scanf("%d",&kill);
			deleteNode(kill);
			printf("\n%d is deleted from the BST\n",kill);
			break;
		default:
			printf("Invalid response\n");
			break;
	}
	printf("\nDo you want to continue?(y/n)\n");
	scanf(" %c", &ans);
	}while(ans == 'y' || ans == 'Y');

	getch();
}



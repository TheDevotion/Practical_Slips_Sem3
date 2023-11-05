/*
Menu driven BST.
1. Create BST
2.Preorder
3. Postorder
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
		root = createNode(data);
	}
	else if(data <= root->data) {
		root -> left = insertNode(root -> left, data);
	}else {
		root -> right = insertNode(root -> right, data);
	}
	return root;
}

void preorder(Node* root){
	if(root == NULL) {
		return;
	}
	printf("%d ",root -> data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node* root){
	if(root == NULL) {
		return;
	}

	postorder(root->left);
	postorder(root->right);
	printf("%d ",root -> data);
}


void main() {
	Node* root = NULL;
	int n,data,choice,i;
	char ans;

	clrscr();


	do{
		printf("---Binary Search Tree----\n");
		printf("1.Create a BST with n nodes\n");
		printf("2.PreOrder traversal of BST\n");
		printf("3.PostOrder traversal of BST\n");
		printf("\nChoose any one option : ");
		scanf("%d", &choice);

	switch(choice){
		case 1:
			printf("How many Nodes you want in your BST?\n");
			scanf("%d",&n);
			printf("Give Nodes:\n");
			for(i=0;i<n;i++){
				scanf("%d",&data);
				root = insertNode(root,data);
			}
			break;
		case 2 :
			printf("\nPreorder Traveral:\n");
			preorder(root);
			break;
		case 3:
			printf("\nPostorder Trraversal:\n");
			postorder(root);
			break;
		default:
			printf("Invalid Choice!\n");
			break;

		}

		printf("\nDo you want to continue?(Y/N)\n");
		scanf(" %c",&ans);

       }while(ans == 'y' || ans == 'Y');
getch();
}




































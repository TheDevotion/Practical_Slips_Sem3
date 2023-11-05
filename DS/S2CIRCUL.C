/*
Write a C program to create a circular doubly linked list and display it
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// defining structure of node

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

// Global declaration of head and tail.
Node* head;
Node* tail;

// Creating a node.

Node * getNewNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode -> data = data;
	newNode -> next = NULL;
	newNode -> prev = NULL;

	return newNode;
}

void create(int data) {
	Node* newNode = getNewNode(data);

	if(head == NULL) {
		head = tail = newNode;
		head -> next = newNode;
		head -> prev = newNode;
	}
	else {
		newNode -> prev = tail;
		newNode -> next = head;
		tail -> next = newNode;
		head -> prev = newNode;
		tail = newNode;
	}
}

void display() {
	Node* temp = head;

	do {
		printf("%d -> ", temp -> data);
		temp = temp -> next;
	}while(temp -> next != head);

	printf("%d ->",temp->data);
	temp = temp -> next;
	printf("%d", temp -> data);
}

void main() {
	int data,n,i;

	clrscr();
	head = NULL;

	printf("How many elements you want in your doubly circular linked list?\n");
	scanf("%d", &n);

	printf("Enter data:\n");
	for(i=0; i<n; i++) {
		scanf("%d",&data);
		create(data);
	}

	display();
	getch();
}








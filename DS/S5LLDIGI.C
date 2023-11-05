/*
Write a C program to create a linked list with a given number in
which data part of each node contains an individual digit of the number
(eg 368 will be stored as  3  -> 6 -> 8
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* head;

void insertAtHead(int data) {

	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode -> data = data;
	newNode -> next = NULL;

	if(head == NULL) {
		head = newNode;
	}
	else{
		newNode -> next = head;
		head = newNode;
	}
}

void display() {
	Node* temp = head;
	if(head == NULL) {
		printf("List is empty!\n");
	}

	while(temp != NULL) {
		printf(" %d -> ", temp -> data);
		temp = temp -> next;
	}
}

void main() {
	int i,num,rem;

	clrscr();
	head = NULL;

	printf("Give the number you want to store in the linked list:\n");
	scanf("%d", &num);

	// storing each digit
	while(num > 0) {
		rem = num % 10;
		insertAtHead(rem);
		num = num/10;
	}

	printf(" The given number is stored in a linked list as:\n");
	display();

	getch();
}




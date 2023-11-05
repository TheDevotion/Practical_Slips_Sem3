/*
	Write a C program to accept a string from a user
	and reverse it using static implementation of stack.
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAX 100

// creating a stack (using array)
int stack[MAX];
int top = -1;

void push(char data) {
	if(top == MAX -1) {
		printf("Stack is full (stack overflow)\n Cannot push");
	}
	top ++;
	stack[top] = data;
}

void pop() {
	if( top == -1) {
		printf("Stack is empty! Cannot pop\n");
	}
	top --;
}
char getTop() {
	if(top != -1) {
		return stack[top];
	}
	return '\0';
}

void main() {
	int i;
	char str[50];
	char x, ltr;

	clrscr();

	printf("Give the string:");
	gets(str);

	// storing the string in stack:

	for(i=0; i<strlen(str); i++) {
		x = str[i];
		push(x);
	}

	printf("Reverserd string is:\n");

	for(i=0; i<strlen(str); i++) {
		ltr = getTop();
		pop();
		printf("%c",ltr);
	}

	 getch();
}




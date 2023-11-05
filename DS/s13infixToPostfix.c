#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for the stack
typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

void push(Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++(stack->top)] = value;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

int isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(char* infix) {
    Stack stack;
    initialize(&stack);
    int i, j;
    char postfix[MAX_SIZE];
    j = 0;

    for (i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isOperand(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                printf("Invalid expression: Missing opening parenthesis '('.\n");
                return;
            } else {
                pop(&stack);
            }
        } else {
            while (!isEmpty(&stack) && precedence(ch) <= precedence(stack.items[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX_SIZE];

    printf("Enter the infix expression: ");
    gets(infix);

    infixToPostfix(infix);

    getch();
    return 0;
}

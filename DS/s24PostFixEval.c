#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int* items;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
    stack->items = (int*)malloc(MAX_SIZE * sizeof(int));
}

int isFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++(stack->top)] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

int evaluatePostfix(char* postfix) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter the postfix expression: ");
    fgets(postfix, MAX_SIZE, stdin);

    int result = evaluatePostfix(postfix);

    printf("Result of the postfix expression: %d\n", result);

    return 0;
}

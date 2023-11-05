#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Stack functions
void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

void push(struct Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++(stack->top)] = value;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

int evaluatePostfix(char* exp) {
    struct Stack stack;
    initialize(&stack);
    int i, result, operand1, operand2;

    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0');
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (exp[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            push(&stack, result);
        }
    }
    return pop(&stack);
}

int main() {
    char postfixExp[MAX_SIZE];
    int result;

    printf("Enter the postfix expression: ");
    gets(postfixExp);

    result = evaluatePostfix(postfixExp);
    printf("Evaluated result: %d\n", result);

    getch();
    return 0;
}


// Create a stack to store the operands.
// Iterate over the postfix expression from left to right.
// If the current element is an operand, push it onto the stack.
// If the current element is an operator, pop the top two operands from the stack, perform the operation, and push the result back onto the stack.
// Repeat steps 3 and 4 until you reach the end of the expression.
// The final value on the stack is the result of the expression.
// Here is an example of how the function would evaluate the postfix expression 2 3 +:

// Push 2 onto the stack.
// Push 3 onto the stack.
// Pop the top two operands from the stack (which are 3 and 2) and add them together.
// Push the result (which is 5) onto the stack.
// The final value on the stack is 5, which is the result of the expression.

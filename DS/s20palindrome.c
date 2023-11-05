#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

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

int isPalindrome(char* string) {
    Stack stack;
    initialize(&stack);

    int length = strlen(string);
    int i;
    int mid = length / 2;

    for (i = 0; i < mid; i++) {
        push(&stack, string[i]);
    }

    if (length % 2 != 0) {
        i++; // Skip the middle character if the length is odd
    }

    while (string[i] != '\0') {
        if (string[i] != pop(&stack)) {
            return 0; // Not a palindrome
        }
        i++;
    }

    return 1; // It is a palindrome
}

int main() {
    char string[MAX_SIZE];

    printf("Enter a string: ");
    gets(string);

    if (isPalindrome(string)) {
        printf("The entered string is a palindrome.\n");
    } else {
        printf("The entered string is not a palindrome.\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    free(temp);
    return poppedValue;
}

int isEmpty() {
    return (top == NULL);
}

void reverseString(char* string) {
    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        push(string[i]);
    }

    for (int i = 0; i < length; i++) {
        string[i] = pop();
    }
}

int main() {
    char input[MAX_SIZE];

    printf("Enter a string: ");
    gets(input);

    reverseString(input);

    printf("Reversed string: %s\n", input);

    getch();
    return 0;
}

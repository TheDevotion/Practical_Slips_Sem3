#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Structure for the queue
typedef struct {
    int front, rear, capacity;
    int *array;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->rear == queue->capacity - 1);
}

int isEmpty(Queue* queue) {
    return (queue->front > queue->rear);
}

void insert(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full, cannot insert.\n");
        return;
    }
    queue->array[++(queue->rear)] = item;
    printf("Inserted %d into the queue.\n", item);
}

void delete(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot delete.\n");
        return;
    }
    int item = queue->array[(queue->front)++];
    printf("Deleted %d from the queue.\n", item);
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    int choice, item, capacity;

    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);

    Queue* queue = createQueue(capacity);

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insert(queue, item);
                break;
            case 2:
                delete(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

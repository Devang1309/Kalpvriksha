#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* array;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* create_queue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int size(Queue* queue) {
    printf("%d\n", queue->rear - queue->front + 1);
    return queue->rear - queue->front + 1;
}

int isEmpty(Queue* queue) {
    return queue->rear < queue->front;
}

void enqueue(Queue* queue, int item) {
    if (queue->rear == queue->capacity - 1) {
        printf("Overflow Condition - Queue is full!\n");
        return;
    }
    queue->array[++queue->rear] = item;
    printf("%d is added to the queue\n", item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Underflow Condition - Queue is empty!\n");
        return -1;
    }
    int dequeued_item = queue->array[queue->front++];
    printf("%d\n", dequeued_item);
    return dequeued_item;
}

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Underflow Condition - Queue is empty!\n");
        return -1;
    }
    printf("%d\n", queue->array[queue->front]);
    return queue->array[queue->front];
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Underflow Condition - Queue is empty!\n");
        return;
    }

    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d\n", queue->array[i]);
    }
}

int main() {
    int capacity;
    printf("Enter the capacity of the queue:\n");
    scanf("%d", &capacity);
    Queue* queue = create_queue(capacity);

    int choice;
    int item;

    while (1) {
        printf("Enter the operation you want to perform:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. Size\n6. Display\n7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item:\n");
                scanf("%d", &item);
                enqueue(queue, item);
                break;

            case 2:
                printf("The deleted item is: ");
                dequeue(queue);
                break;

            case 3:
                printf("The element at the front is: ");
                peek(queue);
                break;

            case 4:
                if (isEmpty(queue) == 0) {
                    printf("The queue is not empty!\n");
                } else {
                    printf("Queue is empty!\n");
                }
                break;

            case 5:
                printf("The size of the queue is: ");
                size(queue);
                break;

            case 6:
                printf("The queue is:\n");
                display(queue);
                break;

            case 7:
                printf("Exit...\n");
                free(queue->array);  
                free(queue);  
                return 0;

            default:
                printf("Enter a valid choice!\n");
                break;
        }
    }

    return 0;
}

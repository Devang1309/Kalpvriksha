#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* array;
    int front, rear, size, capacity;
} Queue;

Queue* create_queue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = queue->size;
    queue->rear = queue->size;
    queue->array = (int*)malloc(queue->capacity*sizeof(int));
    return queue;
}

int isQueueEmpty(Queue* queue) {
    return queue->size == 0;
}

int isQueueFull(Queue* queue) {
    return queue->size == queue->capacity;
}

void enqueue(Queue* queue, int value) {
    if (isQueueFull(queue)) {
        printf("Overflow Condition - Queue is full!\n");
        return;
    }
    queue->array[queue->rear] = value;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Underflow Condition - Queue is empty!\n");
        return -1;
    }
    int value = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

int front(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->array[queue->front];
}

int rear(Queue* queue){
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    return queue->array[queue->rear];
}

void rotateQueue(Queue* queue) {
    int temp = dequeue(queue);
    enqueue(queue, temp);
}

typedef struct Stack {
    Queue* queue;
} Stack;

Stack* create_stack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->queue = create_queue(capacity);
    return stack;
}

int isStackEmpty(Stack* stack) {
    return isQueueEmpty(stack->queue);
}

void push(Stack* stack, int value) {
    if (isQueueFull(stack->queue)) {
        printf("Overflow Condition - Stack is full!\n");
        return;
    }

    enqueue(stack->queue, value);

    for (int i = 0; i < stack->queue->size - 1; i++) {
        rotateQueue(stack->queue);
    }
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Underflow Condition - Stack is empty!\n");
        return -1;
    }

    return dequeue(stack->queue);
}

int peek(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Underflow Condition - Stack is empty!\n");
        return -1;
    }

    return front(stack->queue);
}

void display(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }

    for(int i=stack->queue->size-1; i>=0; i--){
        printf("%d ", stack->queue->array[i]);
    }
    printf("\n");
}

int size(Stack* stack){
    return stack->queue->size;
}

int main() {
    int capacity;
    printf("Enter the capacity of the stack:\n");
    scanf("%d", &capacity);

    Stack* stack = create_stack(capacity);

    int choice, item;

    while (1) {
        printf("Enter the operation:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Display\n6. Size\n7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item you want to add: ");
                scanf("%d", &item);
                push(stack, item);
                break;

            case 2:
                printf("The popped item is: ");
                printf("%d\n", pop(stack));
                break;

            case 3:
                printf("The top element is: ");
                printf("%d\n", peek(stack));
                break;

            case 4:
                if (isStackEmpty(stack)) {
                    printf("The stack is empty!\n");
                } else {
                    printf("The stack is not empty!\n");
                }
                break;

            case 5:
                printf("The stack is: ");
                display(stack);
                break;

            case 6:
                printf("The size of stack is: ");
                printf("%d\n", size(stack));
                break;

            case 7:
                printf("Exit...\n");
                free(stack->queue->array);
                free(stack->queue);
                free(stack);
                return 0;

            default:
                printf("Enter a valid choice!\n");
                break;
        }
    }

    return 0;
}

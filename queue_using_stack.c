#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* array;
    int top;
    int capacity;
} Stack;

Stack* create_stack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Overflow Condition - Stack is full!\n");
        return;
    }
    stack->array[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Underflow Condition - Stack is empty!\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Underflow Condition - Stack is empty!\n");
        return -1;
    }
    return stack->array[stack->top];
}

int size(Stack* stack) {
    return stack->top + 1;
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

typedef struct Queue {
    Stack* stack1;
    Stack* stack2;
    int capacity;
} Queue;

Queue* create_queue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->stack1 = create_stack(capacity);
    queue->stack2 = create_stack(capacity);
    return queue;
}

int isQueueEmpty(Queue* queue) {
    return isEmpty(queue->stack1) && isEmpty(queue->stack2);
}

void enqueue(Queue* queue, int value) {
    if (size(queue->stack1) + size(queue->stack2) == queue->capacity) {
        printf("Overflow Condition - Queue is full!\n");
        return;
    }

    push(queue->stack1, value);
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Underflow Condition - Queue is empty!\n");
        return -1;
    }

    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }

    return pop(queue->stack2);
}

int peekQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Underflow Condition - Queue is empty!\n");
        return -1;
    }

    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }

    return peek(queue->stack2);
}

void displayQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    if (!isEmpty(queue->stack1)) {
        display(queue->stack1);
    }

    for (int i = queue->stack2->top; i >= 0; i--) {
        printf("%d ", queue->stack2->array[i]);
    }
    printf("\n");
}

int sizeQueue(Queue* queue) {
    return size(queue->stack1) + size(queue->stack2);
}

int main() {
    int capacity;
    printf("Enter the capacity of the queue:\n");
    scanf("%d", &capacity);
    Queue* queue = create_queue(capacity);

    int choice;
    int item;

    while (1) {
        printf("Enter the operation you want to perform:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. Display\n6. Size\n7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item you want to add: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;

            case 2:
                printf("The deleted item is: ");
                printf("%d\n", dequeue(queue));
                break;

            case 3:
                printf("The front element is: ");
                printf("%d\n", peekQueue(queue));
                break;

            case 4:
                if (isQueueEmpty(queue)) {
                    printf("The queue is empty!\n");
                } 
                else {
                    printf("The queue is not empty!\n");
                }
                break;

            case 5:
                printf("The queue is: ");
                displayQueue(queue);
                break;

            case 6:
                printf("The size of the queue is: ");
                printf("%d\n", sizeQueue(queue));
                break;

            case 7:
                printf("Exit...\n");
                free(queue->stack1->array);
                free(queue->stack2->array);
                free(queue->stack1);
                free(queue->stack2);
                free(queue);
                return 0;

            default:
                printf("Enter a valid choice!\n");
                break;
        }
    }

    return 0;
}

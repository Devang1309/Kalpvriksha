#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void queue_initialization(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int value) {
    Node* newNode = create_node(value);
    if (!newNode) {
        printf("Overflow Condition!\n");
        return;
    }

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } 
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Underflow Condition!\n");
        return;
    } 
    else {
        printf("%d\n", queue->front->data);
        Node* temp = queue->front;
        queue->front = queue->front->next;
        temp->next = NULL;

        if (queue->front == NULL) {
            queue->rear = NULL;
        }

        free(temp);
    }
}

int peek(Queue* queue) {
    if (!isEmpty(queue)) {
        printf("%d\n", queue->front->data);
        return queue->front->data;
    } 
    else {
        printf("Queue is Empty!\n");
        return -1;
    }
}

int size(Queue* queue) {
    int count = 0;
    Node* temp = queue->front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void display(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));  
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }
    queue_initialization(queue);

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
                printf("The size of the queue is: %d\n", size(queue));
                break;

            case 6:
                printf("The queue is:\n");
                display(queue);
                break;

            case 7:
                printf("Exit...\n");
                free(queue);  
                return 0;

            default:
                printf("Enter a valid choice!\n");
                break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* create_node(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

typedef struct {
    Node* head;
} Stack;

void stack_initialization(Stack* stack){
    stack->head = NULL;
}

int isEmpty(Stack* stack){
    return stack->head == NULL;
}

void push(Stack* stack, int value){
    Node* newNode = create_node(value);
    if (!newNode) {
        printf("Overflow Condition!\n");
        return;
    }

    newNode->next = stack->head;
    stack->head = newNode;
}

void pop(Stack* stack){
    if (isEmpty(stack)) {
        printf("Underflow Condition!\n");
        return;
    } else {
        printf("%d\n", stack->head->data);
        Node* temp = stack->head;
        stack->head = stack->head->next;
        temp->next = NULL;
        free(temp);
    }
}

int peek(Stack* stack){
    if (!isEmpty(stack)) {
        printf("%d\n", stack->head->data);
        return stack->head->data;
    } else {
        printf("Stack is Empty!");
        return -1;
    }
}

int size(Stack* stack){
    int count = 0;
    Node* temp = stack->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void display(Stack* stack){
    if (stack->head == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    Node* temp = stack->head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));  
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }
    
    stack_initialization(stack);

    int choice;
    int item;

    while (1) {
        printf("Enter the operation you want to perform:\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Size\n6. Display\n7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item you want to push\n");
                scanf("%d", &item);
                push(stack, item);
                break;

            case 2:
                printf("The deleted item is: ");
                pop(stack);
                break;

            case 3:
                printf("The element at the top is: ");
                peek(stack);
                break;

            case 4:
                if (isEmpty(stack) == 0) {
                    printf("The stack is not empty!\n");
                } else {
                    printf("Stack is empty!\n");
                }
                break;

            case 5:
                printf("The size of the stack is: %d\n", size(stack));
                break;

            case 6:
                printf("The stack is:\n");
                display(stack);
                break;

            case 7:
                printf("Exit...\n");
                free(stack);  
                return 0;

            default:
                printf("Enter a valid choice!\n");
                break;
        }
    }

    return 0;
}

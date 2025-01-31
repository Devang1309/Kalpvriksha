#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* array;
    int top;
    int capacity;
} Stack;

Stack* create_stack(int capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity*sizeof(int));

    return stack;
}

int size(Stack* stack){
    printf("%d\n", stack->top+1);
    return stack->top + 1;
}

int isEmpty(Stack* stack){
    return stack->top == -1;
}

void push(Stack* stack, int item, int capacity){
    if(stack->top==capacity-1){
        printf("Overflow Condition - Stack is full!\n");
        return;
    }

    stack->array[++stack->top] = item;
    printf("%d is pushed into stack\n", item);
}

int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Underflow Condition - Stack is empty!\n");
        return -1;
    }

    printf("%d\n", stack->array[stack->top]);
    return stack->array[stack->top--];
}

int peek(Stack* stack){
    if(isEmpty(stack)){
        printf("Underflow Condition - Stack is empty!\n");
        return -1;
    }

    printf("%d\n", stack->array[stack->top]);
    return stack->array[stack->top];
}

void display(Stack* stack, int capacity){
    if(isEmpty(stack)){
        printf("Underflow Condition: Stack is empty!\n");
    }

    for(int i=0; i<capacity; i++){
        printf("%d\n", stack->array[i]);
    }
}

int main(){
    int capacity;
    printf("Enter the capacity of array:\n");
    scanf("%d", &capacity);
    Stack* stack = create_stack(capacity);
    int choice;
    int item;

    while(1){
        printf("Enter the operation you want to perform:\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Size\n6. Display\n7. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the item you want to push\n");
                scanf("%d", &item);
                push(stack, item, capacity);
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
                if(isEmpty(stack)==0){
                    printf("The stack is not empty!\n");
                }
                else{
                    printf("Stack is empty!");
                }
                break;
            
            case 5:
                printf("The size of the stack is: ");
                size(stack);
                break;
            
            case 6:
                printf("The stack is:\n");
                display(stack, capacity);
                break;

            case 7:
                printf("Exit...");
                return 0;

            default:
                printf("Enter a valid choice!\n");
                break;
        }
    }

    return 0;
}
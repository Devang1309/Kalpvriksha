#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

int is_number(int num){
    if(num>=-1000 && num<=1000){
        return 1;
    }

    return 0;
}

void insertAtEnd(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void insertAtBeginning(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int position,int value){
    if(position<1){
        printf("Invalid position\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if(position==1){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    for(int i=1; i<position-1 && temp!=NULL; i++){
        temp = temp->next;
    }

    if(temp==NULL){
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

}

void display(){
    if(head==NULL){
        printf("\n");
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void updateAtPosition(int position, int newValue){
    if(position<1){
        printf("Invalid position\n");
    }

    Node* temp = head;
    for(int i=1; i<position && temp!=NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Invalid position\n");
        return;
    }

    temp->data = newValue;
}

void deleteAtBeginning(){
    if(head==NULL){
        printf("Linked list is empty!\n");
        return;
    }

    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd(){
    if(head==NULL){
        printf("Linked List is empty!\n");
        return;
    }

    if(head->next == NULL){
        free(head);
        head==NULL;
        return;
    }

    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int position){
    if(position<1){
        printf("Invalid position\n");
        return;
    }

    if(head==NULL){
        printf("Linked List is empty!\n");
        return;   
    }

    if(position==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    Node* temp = head;
    for(int i=1; i<position-1 && temp!=NULL; i++){
        temp = temp->next;
    }

    if(temp==NULL || temp->next==NULL){
        printf("Invalid position\n");
    }

    Node* delete_node = temp->next;
    temp->next = temp->next->next;
    free(delete_node);
    
}

int main(){
    int operations;
    scanf("%d", &operations);
    if(operations<1 || operations>100){
        printf("Operations can only be in the range from 1-100!\n");
        return 0;
    }


    int index = 0;
    while(index<operations){
        int choice;
        scanf("%d", &choice);

        int position, number;

        switch(choice){
            case 1:
                scanf("%d", &number);
                if(!is_number(number)){
                    printf("Enter a valid number!");
                    break;
                }

                insertAtEnd(number);
                break;
            
            case 2:
                scanf("%d", &number);
                if(!is_number(number)){
                    printf("Enter a valid number!");
                    break;
                }

                insertAtBeginning(number);
                break;

            case 3:
                scanf("%d", &position);
                scanf("%d", &number);
                if(!is_number(number)){
                    printf("Enter a valid number!");
                    break;
                }

                insertAtPosition(position, number);
                break;
            
            case 4:
                display();
                break;

            case 5:
                scanf("%d", &position);
                scanf("%d", &number);
                if(!is_number(number)){
                    printf("Enter a valid number!");
                    break;
                }

                updateAtPosition(position, number);
                break;
            
            case 6:
                deleteAtBeginning();
                break;
            
            case 7:
                deleteAtEnd();
                break;
            
            case 8:
                scanf("%d", &position);

                deleteAtPosition(position);
                break;
            
            default:
                printf("Enter a valid choice!");
                break;
        }

        index++;
    }

    return 0;
}
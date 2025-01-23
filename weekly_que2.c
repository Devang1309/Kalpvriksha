#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* reverse_group(Node* head, int size) {
    Node* temp = head;
    Node* prev = NULL;
    int count = 0;

    while (temp != NULL && count<size) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;

        count++;
    }

    return prev;
}

Node* reverse_alternate_groups(int size){
    if (head == NULL || size == 1){
        return head;
    } 

    Node* temp = head;
    Node* prev = NULL;
    
    while(temp != NULL) {
        Node* group_start = temp;
        Node* group_end = temp;
        int count = 1;
    
        while (group_end != NULL && count < size){
            group_end = group_end->next;
            count++;
        }

        if (group_end != NULL) {
            Node* next_group = group_end->next;
            group_end->next = NULL; 

            if(prev == NULL){
                head = reverse_group(group_start, size); 
            }
            else {
                prev->next = reverse_group(group_start, size);
            }

            group_start->next = next_group; 
            prev = group_start;
            temp = next_group;
            
            for (int i = 0; i < size && temp != NULL; i++) {
                prev = temp;
                temp = temp->next;
            }
        } 
        else {
            break; 
        }
    }

    return head;
}

void display() {
    if (head == NULL) {
        printf("\n");
        return;
    }

    Node* temp1 = head;
    while (temp1 != NULL) {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}

void create_node(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } 
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

int main() {
    int data;
    while(scanf("%d", &data)==1){
        create_node(data);
        char ch = getchar();
        if(ch=='\n'){
            break;
        }
    }

    int size;
    printf("Size of group: ");
    scanf("%d", &size);

    head = reverse_alternate_groups(size);

    printf("Final linked list is: ");
    display();

    return 0;
}

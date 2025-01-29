#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int id;
    char severity_level[100];
    struct Node* next;
} Node;

Node* head = NULL;

void create_node(int patient_id, char severity[100]){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = patient_id;
    int index = 0;
    while(severity[index]!='\0'){
        newNode->severity_level[index] = severity[index];
        index++;
    }
    newNode->next = NULL;

    if(head==NULL){
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

void display(){
    if(head==NULL){
        printf("\n");
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->id);
        int index = 0;
        while(temp->severity_level[index]!='\0'){
            printf("%c", temp->severity_level[index]);
            index++;
        }
        printf("\n");
        temp = temp->next;
    }
    printf("\n");
}

void sort_linked_list(){
    Node* critical_head = (Node*)malloc(sizeof(Node));
    critical_head->next = NULL;
    Node* serious_head = (Node*)malloc(sizeof(Node));
    serious_head->next = NULL;
    Node* stable_head = (Node*)malloc(sizeof(Node));
    stable_head->next = NULL;

    Node* temp = head;
    Node* prev = (Node*)malloc(sizeof(Node));
    while(temp!=NULL){
        Node* front = temp->next;
        if(temp->severity_level=="critical"){
            Node* critical_temp = critical_head;
            while(critical_temp->next!=NULL){
                critical_temp = critical_temp->next;
            }

            critical_temp->next = temp;
            prev->next = front;
            prev = temp;
            temp->next = NULL; 
        }
        if(temp->severity_level=="serious"){
            Node* serious_temp = serious_head;
            while(serious_temp->next!=NULL){
                serious_temp = serious_temp->next
            }

            serious_temp->next = temp;
            prev->next = front;
            prev = temp;
            temp->next = NULL;
        }
        if(temp->severity_level=="stable"){
            Node* stable_temp = stable_head;
            while(stable_temp->next!=NULL){
                stable_temp = stable_temp->next;
            }

            stable_temp->next = temp;
            prev->next = front;
            prev = temp;
            temp->next = NULL;
        }

        temp = front;
    }

}

int main(){
    int number_patient;
    scanf("%d", &number_patient);

    int operation = number_patient;

    int patient_id;
    char severity[100];

    while(operation){
        scanf("%d", &patient_id);
        getchar();

        scanf("%s", &severity);
        char ch = getchar();

        create_node(patient_id, severity);

        if(ch=='\n'){
            operation--;
        }
    }

    display();

    sort_linked_list();

    return 0;
}
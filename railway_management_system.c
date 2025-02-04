#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    GENERAL,
    SENIOR_CITIZEN,
    VIP
} PassengerType;

typedef struct passenger{
    int passengerId;
    PassengerType type;
    char* passengerName;
} passenger;

typedef struct passengerList{
    passenger** passengerQueue;
    int front;
    int rear;
    int capacity;
    int size;
} passengerList;

char* passengerTypeName[3];

void initializePassengerTypeName(){
    passengerTypeName[0] = (char*)malloc(100*sizeof(char));
    passengerTypeName[1] = (char*)malloc(100*sizeof(char));
    passengerTypeName[2] = (char*)malloc(100*sizeof(char));
    passengerTypeName[0] = "GENERAL";
    passengerTypeName[1] = "SENIOR_CITIZEN";
    passengerTypeName[2] = "VIP";
}

void createPassengerList(passengerList* passengerDetail){
    passengerDetail->front = -1;
    passengerDetail->rear = -1;
    passengerDetail->capacity = 100;
    passengerDetail->size = 0;
    passengerDetail->passengerQueue = (passenger**)malloc(passengerDetail->capacity*sizeof(passenger*));
}

int isEmpty(passengerList* passengerDetail){
    if(passengerDetail->front==-1){
        return 1;
    }

    return 0;
}

int isFull(passengerList* passengerDetail){
    if(passengerDetail->rear==passengerDetail->capacity-1){
        return 1;
    }

    return 0;
}

void merge(passenger** array, int low, int mid, int high){
    passenger** temp = (passenger**)malloc(100*sizeof(passenger*));
    int index = 0;

    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high){
        if(array[left]->type>=array[right]->type){
            temp[index++] = array[left++];
        }
        else{
            temp[index++] = array[right++]; 
        }
    }

    while(left<=mid){
        temp[index++] = array[left++];
    }

    while(right<=high){
        temp[index++] = array[right++];
    }

    for(int i=low; i<=high; i++){
        array[i] = temp[i-low];
    }

    free(temp);
}

void merge_sort(passenger** array, int low, int high){
    if(low>=high){
        return;
    }

    int mid = low+(high-low)/2;
    merge_sort(array, low, mid);
    merge_sort(array, mid+1, high);
    merge(array, low, mid, high);
}

void enqueue(passengerList* passengerDetail){
    if(isFull(passengerDetail)){
        passengerDetail->capacity *= 2;
        passengerDetail->passengerQueue = (passenger**)realloc(passengerDetail->passengerQueue, passengerDetail->capacity*sizeof(passenger*));
    }
    int id;
    char* name = (char*)malloc(100*sizeof(char));
    char* passengerType = (char*)malloc(100*sizeof(char));

    scanf(",%d, %[^,], \"%[^\"]\";", &id, passengerType, name);
    if(passengerDetail->front == -1){
        passengerDetail->front = 0;
    }

    passenger* newPassenger = (passenger*)malloc(sizeof(passenger));
    newPassenger->passengerId = id;
    newPassenger->passengerName = name;
    if(strcmp(passengerType, "GENERAL")==0){
        newPassenger->type = GENERAL;
    }
    else if(strcmp(passengerType, "SENIOR_CITIZEN")==0){
        newPassenger->type = SENIOR_CITIZEN;
    }
    else if(strcmp(passengerType, "VIP")==0){
        newPassenger->type = VIP;
    }
    else{
        printf("Enter a valid passenger type\n");
        return;
    }

    passengerDetail->passengerQueue[++passengerDetail->rear] = newPassenger;
    passengerDetail->size++;
    merge_sort(passengerDetail->passengerQueue, passengerDetail->front, passengerDetail->rear-1);
}

void display(passengerList* passengerDetail){
    printf("Waiting Passengers: \n");
    if(isEmpty(passengerDetail)){
        printf("No passengers\n");
        return;
    }

    for(int i=passengerDetail->front; i<=passengerDetail->rear; i++){
        printf("ID %d, Name: %s, Type: %s\n", passengerDetail->passengerQueue[i]->passengerId, passengerDetail->passengerQueue[i]->passengerName, passengerTypeName[passengerDetail->passengerQueue[i]->type]);
    }
}

void dequeue(passengerList* passengerDetail){
    if(isEmpty(passengerDetail)){
        printf("Queue Underflow\n");
        return;
    }

    printf("Serving Passengers:\n");
    printf("ID %d, Name: %s, Type: %s\n", passengerDetail->passengerQueue[passengerDetail->front]->passengerId, passengerDetail->passengerQueue[passengerDetail->front]->passengerName, passengerTypeName[passengerDetail->passengerQueue[passengerDetail->front]->type]);
    passengerDetail->front++;
}

int main(){
    int operation;
    scanf("%d", &operation);

    passengerList* passengerDetail = (passengerList*)malloc(sizeof(passengerList));
    passengerDetail->passengerQueue = NULL;     

    createPassengerList(passengerDetail);
    initializePassengerTypeName();

    while(operation){
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
            enqueue(passengerDetail);
            break;

            case 2:
            dequeue(passengerDetail);
            break;

            case 3:
            display(passengerDetail);
            break;

            default:
            break;
        }

        operation--;
    }

    return 0;
}
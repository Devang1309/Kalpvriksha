#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void display(Node* head) {
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

Node* reverse(Node* head) {
    Node* temp2 = head;
    Node* prev = NULL;

    while (temp2 != NULL) {
        Node* front = temp2->next;
        temp2->next = prev;
        prev = temp2;
        temp2 = front;
    }

    return prev;
}

void create_node(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

int main() {
    int count, size;
    scanf("%d", &count);
    scanf("%d", &size);
    getchar();  

    while (count) {
        char choice;
        scanf("%c", &choice);
        getchar();

        if (choice == 'A') {
            int data;
            scanf("%d", &data);
            getchar();  
            create_node(data);
        }
        
        if (choice == 'S') {
            int sum = 0;
            Node* newHead = reverse(head);
            Node* current = newHead;

            int index = size;
            while (index != 0) {
                if (current != NULL) {
                    sum += current->data;
                    current = current->next;
                } else {
                    break;
                }
                index--;
            }

            printf("%d\n", sum);

            head = reverse(newHead);
        }

        count--;  
    }

    return 0;
}

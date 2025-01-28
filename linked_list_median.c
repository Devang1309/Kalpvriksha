#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head1 = NULL;
Node* head2 = NULL;
Node* merged_head = NULL;

void create_node(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } 
    else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* merge_two_sorted_linked_list(Node* left, Node* right) {
    Node* dummy = (Node*)malloc(sizeof(Node));  
    Node* temp = dummy;

    while (left != NULL && right != NULL) {
        if (left->data <= right->data) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    if (left != NULL) {
        temp->next = left;
    } 
    else {
        temp->next = right;
    }

    return dummy->next;
}

Node* find_middle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* sort_linked_list(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* middle = find_middle(head);

    Node* right = middle->next;
    middle->next = NULL;
    Node* left = head;

    left = sort_linked_list(left);
    right = sort_linked_list(right);

    return merge_two_sorted_linked_list(left, right);
}

void display(Node* head) {
    if (head == NULL) {
        printf("\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

float find_median(Node* head) {
    if (head == NULL) return 0;

    Node* temp = head;
    int length = 0;
    
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    if (length % 2 == 1) {
        for (int i = 0; i < length / 2; i++) {
            head = head->next;
        }
        return head->data;
    }
    else {
        for (int i = 0; i < length / 2 - 1; i++) {
            head = head->next;
        }
        int mid1 = head->data;
        head = head->next;
        int mid2 = head->data;

        float answer = (mid1 + mid2) / 2.0;
        return answer;
    }
}

int main() {
    int value;
    printf("Enter the elements of first linked list: \n");
    while (scanf("%d", &value) == 1) {
        create_node(&head1, value);
        char ch = getchar();

        if (ch == '\n') {
            break;
        }
    }

    printf("Enter the elements of second linked list: \n");
    while (scanf("%d", &value) == 1) {
        create_node(&head2, value);
        char ch = getchar();

        if (ch == '\n') {
            break;
        }
    }

    head1 = sort_linked_list(head1);
    head2 = sort_linked_list(head2);

    merged_head = merge_two_sorted_linked_list(head1, head2);

    printf("Merged Linked List: \n");
    display(merged_head);

    float median = find_median(merged_head);
    printf("Median of the merged list: %f\n", median);

    return 0;
}

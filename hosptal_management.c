#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int id;
    char severity_level[100];
    struct Node *next;
} Node;

typedef struct
{
    int id;
} Map;

int search_map(Map map[], int map_index, int id)
{
    for (int i = 0; i < map_index; i++)
    {
        if (map[i].id == id)
            return i;
    }

    return -1;
}
Node *head = NULL;

void create_node(int patient_id, char severity[100])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->id = patient_id;
    strcpy(newNode->severity_level, severity);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->id);
        printf("%s\n", temp->severity_level);
        temp = temp->next;
    }
    printf("\n");
}

void sort_linked_list()
{
    Node *critical_head = (Node *)malloc(sizeof(Node));
    critical_head->next = NULL;
    Node *serious_head = (Node *)malloc(sizeof(Node));
    serious_head->next = NULL;
    Node *stable_head = (Node *)malloc(sizeof(Node));
    stable_head->next = NULL;

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        Node *front = temp->next;
        if (strcmp(temp->severity_level, "critical") == 0)
        {
            Node *critical_temp = critical_head;
            while (critical_temp->next != NULL)
            {
                critical_temp = critical_temp->next;
            }
            critical_temp->next = temp;
        }
        else if (strcmp(temp->severity_level, "serious") == 0)
        {
            Node *serious_temp = serious_head;
            while (serious_temp->next != NULL)
            {
                serious_temp = serious_temp->next;
            }
            serious_temp->next = temp;
        }
        else if (strcmp(temp->severity_level, "stable") == 0)
        {
            Node *stable_temp = stable_head;
            while (stable_temp->next != NULL)
            {
                stable_temp = stable_temp->next;
            }
            stable_temp->next = temp;
        }

        temp->next = NULL;
        temp = front;
    }

    Node *move = critical_head;
    while (move->next != NULL)
    {
        move = move->next;
    }
    move->next = serious_head->next;

    move = critical_head;
    while (move->next != NULL)
    {
        move = move->next;
    }
    move->next = stable_head->next;

    head = critical_head->next;
}

void severity_input(char severity[100], int patient_id){
    printf("Enter the correct severity\n");
    scanf("%s", severity);

    if (strcmp(severity,"critical")==0 ||strcmp(severity,"serious")==0 || strcmp(severity,"stable")==0)
    {
        create_node(patient_id, severity);
        return;
    }
    else{
        severity_input(severity, patient_id);
    }
}

int main()
{
    int number_patient;
    scanf("%d", &number_patient);
    Map map[100];
    int map_index = 0;
    int operation = number_patient;
    int patient_id;
    char severity[100];

    while (operation!=0)
    {
        scanf("%d", &patient_id);
        int index = search_map(map, map_index, patient_id);
        getchar();
        scanf("%s", severity);

        if (index != -1)
        {
            printf("Id is already used.\n");
            continue;
        }

        if (strcmp(severity,"critical")==0 ||strcmp(severity,"serious")==0 || strcmp(severity,"stable")==0)
        {
            create_node(patient_id, severity);
        }
        else{
            severity_input(severity, patient_id);
        }
        if (index == -1)
        {
            map[map_index].id = patient_id;
            map_index++;
        }
        

        operation--;
    }

    sort_linked_list();

    printf("Sorted linked list is: \n");
    display();

    return 0;
}

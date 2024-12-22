#include <stdio.h>
#include <string.h>

typedef struct user {
    int id, age;
    char name[20];
} USER;

void create_rec() {
    FILE *fp;
    USER user, temp;

    fp = fopen("user.txt", "r+"); 
    if (fp == NULL) {
        fp = fopen("user.txt", "a");
        if (fp == NULL) {
            printf("Error opening file!\n");
            return;
        }
    }

    printf("Enter user Id: ");
    scanf("%d", &user.id);

    while (fscanf(fp, "%d %d %[^\n]", &temp.id, &temp.age, temp.name) == 3) {   // To check duplicate id
        if (temp.id == user.id) {
            printf("Error: This id already exists!\n");
            fclose(fp);
            return;
        }
    }

    printf("Enter user age: ");
    scanf("%d", &user.age);

    while (getchar() != '\n'); 

    printf("Enter user name: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = 0; 

    fprintf(fp, "%d %d %s\n", user.id, user.age, user.name);
    fclose(fp);
    printf("Record saved successfully.\n");
}


void read_rec() {
    FILE *fp;
    USER user;

    fp = fopen("user.txt", "r");
    if (fp == NULL) {
        printf("Error opening file! File might not exist.\n");
        return;
    }

    printf("Id\tAge\tName\n");

    while (fscanf(fp, "%d %d %[^\n]", &user.id, &user.age, user.name) == 3) {
        printf("%d\t%d\t%s\n", user.id, user.age, user.name);
    }

    fclose(fp);
}

void delete_rec() {
    FILE *fp1, *fp2;
    int tid, flag = 0;
    USER user;

    fp1 = fopen("user.txt", "r");
    if (fp1 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fp2 = fopen("temp.txt", "w");
    if (fp2 == NULL) {
        fclose(fp1);
        printf("Error creating temporary file!\n");
        return;
    }

    printf("Enter ID to be deleted: ");
    scanf("%d", &tid);

    while (fscanf(fp1, "%d %d %[^\n]", &user.id, &user.age, user.name) == 3) {
        if (user.id == tid) {
            flag = 1; 
        } else {
            fprintf(fp2, "%d %d %s\n", user.id, user.age, user.name);
        }
    }

    fclose(fp1);
    fclose(fp2);

    remove("user.txt");
    rename("temp.txt", "user.txt");

    if (flag) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Record with ID %d not found!\n", tid);
    }
}

void update_rec() {
    FILE *fp1, *fp2;
    int tid, flag = 0;
    USER user;

    fp1 = fopen("user.txt", "r");
    if (fp1 == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fp2 = fopen("temp.txt", "w");
    if (fp2 == NULL) {
        fclose(fp1);
        printf("Error creating temporary file!\n");
        return;
    }

    printf("Enter ID to be updated: ");
    scanf("%d", &tid);

    while (fscanf(fp1, "%d %d %[^\n]", &user.id, &user.age, user.name) == 3) {
        if (user.id == tid) {
            flag = 1;
            printf("Current values: \n");
            printf("ID:   %d\n", user.id);
            printf("Age:  %d\n", user.age);
            printf("Name: %s\n", user.name);

            printf("Enter new age: ");
            scanf("%d", &user.age);

            while (getchar() != '\n'); // Clear the newline character from the buffer

            printf("Enter new name: ");
            fgets(user.name, sizeof(user.name), stdin);
            user.name[strcspn(user.name, "\n")] = 0; // Remove trailing newline
        }
        fprintf(fp2, "%d %d %s\n", user.id, user.age, user.name);
    }

    fclose(fp1);
    fclose(fp2);

    remove("user.txt");
    rename("temp.txt", "user.txt");

    if (flag) {
        printf("Record updated successfully.\n");
    } else {
        printf("Record with ID %d not found!\n", tid);
    }
}

int main() {
    int choice;

    do {
        printf("\n\t1. Create record\n");
        printf("\t2. Read records\n");
        printf("\t3. Update record\n");
        printf("\t4. Delete record\n");
        printf("\t5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_rec();
                break;
            case 2:
                read_rec();
                break;
            case 3:
                update_rec();
                break;
            case 4:
                delete_rec();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}


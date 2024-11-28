#include <stdio.h>

typedef struct user{
	int id, age;
	char name[20];
} USER;

void create_rec(){
	FILE *fp;
	USER user;
	
	fp = fopen("user.txt", "ab");
	
	printf("Enter user Id: ");
	scanf("%d/n", &user.id);
	printf("Enter user age: ");
	scanf("%d/n", &user.age);
	printf("Enter user name: ");
	fgets(user.name, sizeof(user.name), stdin);
	fgets(user.name, sizeof(user.name), stdin);
	
	fwrite(&user, sizeof(user), 1, fp);
	fclose(fp);
	printf("Record saved successfully.\n");
}

void read_rec(){
	FILE *fp;
	USER user;
	
	fp = fopen("user.txt", "rb");
	
	if(fp==NULL){
		printf("Failed to open the file!\n");
		return;
	}
	
	printf("Id\t\tAge\t\tName\n");
	
	while(fread(&user, sizeof(user), 1, fp)>0){
		printf("%d\t\t%d\t\t%s\n", user.id, user.age, user.name);
	}
	
	fclose(fp);
}

void delete_rec(){
	FILE *fp1,*fp2;
	int tid, flag=0;
	USER user;
	
	fp1 = fopen("user.txt", "rb");
	
	if(fp1==NULL){
		printf("Failed to open the file!\n");
		return;
	}
	
	fp2 = fopen("temp.txt", "wb");
	
	printf("Enter ID to be deleted: ");
	scanf("%d", &tid);
	
	while(fread(&user, sizeof(user), 1, fp1)>0){
		if(user.id == tid){
			flag=1;
		}
		else{
			fwrite(&user, sizeof(user),1, fp2);
		}
	}
	
	fclose(fp1);
	fclose(fp2);
	
	remove("user.txt");
	rename("temp.txt", "user.txt");
	
	if(flag==1){
		printf("Record deleted successfully.\n");
	}
	else{
		printf("Emp ID %d not found!\n", tid);
	}
}

void update_rec(){
	FILE *fp1,*fp2;
	int tid, flag=0;
	
	USER user;
	
	fp1 = fopen("user.txt", "rb");
	
	if(fp1==NULL){
		printf("Failed to open file!\n");
		return;
	}
	
	fp2 = fopen("temp.txt", "wb");
	
	printf("Enter ID to be updated: ");
	scanf("%d", &tid);
	
	while(fread(&user, sizeof(user), 1, fp1)>0){
		if(user.id==tid){
			flag=1;
			printf("Current values: \n");
			printf("ID:   %d\n", user.id);
			printf("Name: %s\n", user.name);
			printf("Age:  %d\n", user.age);
					
			printf("Enter new name: ");
			fgets(user.name, sizeof(user.name), stdin);
			fgets(user.name, sizeof(user.name), stdin);
			printf("Enter new age: ");
			scanf("%d", &user.age);
		}
		
		fwrite(&user, sizeof(user), 1, fp2);
	}
	
	fclose(fp1);
	fclose(fp2);
	
	remove("user.txt");
	rename("temp.txt", "user.txt");
	
	if(flag==1){
		printf("Record updated successfully.\n");
	}
	else{
		printf("Emp ID %d not found!\n", tid);
	}
}

int main(){
	int a;
	
	do{
		printf("\t\t1. Create record\n");
		printf("\t\t2. Read record\n");
		printf("\t\t3. Update record\n");
		printf("\t\t4. Delete record\n");
		printf("\t\t5. Exit\n");
		printf("\t\tEnter your choice(1-5):");
		scanf("%d", &a);
		
		switch(a){
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
				break;
		}
	}while(a!=5);
	
	return 0;
}

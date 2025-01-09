#include <stdio.h>
#include <string.h>

typedef struct{
    char name[100];
    int count;
}info;

info frequency[100];

int main(){
    int row, col;
    char names[10][10][100];
    char* words[100];
    int index = 0;
   
    printf("Enter the no. of rows: ");
    scanf("%d", &row);
   
    printf("Enter the no. of col: ");
    scanf("%d", &col);
   
    printf("Enter the names of elements\n");
   
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("Enter the word at (%d, %d): ", i, j);
            scanf("%s", names[i][j]);
            getchar();
        }
    }
   
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            words[index++] = names[i][j];
        }
    }
   
    int size = 0;
   
    for(int i=0; i<index; i++){
        int found = 0;
        for(int j=0; j<size; j++){
            if(strcmp(frequency[j].name, words[i])==0){
                frequency[j].count++;
                found=1;
                break;
            }
        }
       
        if(!found){
            strcpy(frequency[size].name, words[i]);
            frequency[size].count = 1;
            size++;
        }
    }
   
    printf("Result is: \n");
    for(int i=0; i<size; i++){
        if(frequency[i].count > 1){
            printf("%s - %d \n", frequency[i].name, frequency[i].count);
        }
    }
   
   
    return 0;
}

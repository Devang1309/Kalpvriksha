#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isnumber(char ch){
    if(ch>='0' && ch<='9'){
        return 1;
    }
    else{
        return 0;
    }
}

void bubble_sort(int* array, int length){
    for(int i=0; i<length; i++){
        int flag = 0;
        for(int j=0; j<length-i-1; j++){
            if(array[j]>array[j+1]){
                flag = 1;
                int swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
            }
        }

        if(flag == 0){
            break;
        }
    }
}

int main(){
    int* array = (int*)calloc(1000,sizeof(int));
    int data;

    printf("Enter the elements of array: \n");
    char expression[1000];
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0';

    int i=0; int negative = 0;
    int index = 0;
    while(expression[i]!='\0'){
        if(isnumber(expression[i])){
            array[index] = array[index]*10 + (expression[i]-'0');
        }
        
        if(expression[i]==' ' || expression[i]=='\n'){
            if(negative==1){
                array[index] = array[index]*(-1);
                negative = 0;
            }
            index++;
        }
        
        if(expression[i]=='-'){
            negative = 1;
        }
        
        i++;
    }

    int length = index+1;
    if(index==0){
        printf("Enter a valid input!");
        return 0;
    }

    bubble_sort(array, length);

    printf("Sorted array is: ");
    for(int i=0; i<length; i++){
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}
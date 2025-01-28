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

int binary_search(int* array, int target, int length){
    int start = 0, end = length-1;
    int mid = start+(end-start)/2;

    while(start<=end){
        if(target==array[mid]){
            return 1;
        }
        else if(target<array[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }

        mid = start+(end-start)/2;
    }

    return 0;
}

void sort(int* array, int length){
    for(int i=0; i<length-1; i++){
        for(int j=i+1; j<length; j++){
            if(array[j]<array[i]){
                int swap = array[j];
                array[j] = array[i];
                array[i] = swap;
            }
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

    sort(array, length);

    int target;
    printf("Enter the target to search: \n");
    scanf("%d", &target);

    int answer = binary_search(array, target, length);

    if(answer==1){
        printf("Target is present");
    }
    else{
        printf("Target not found");
    }

    return 0;
}
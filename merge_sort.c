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

void merge(int* array, int low, int mid, int high){
    int* temp = (int*)malloc(1000*sizeof(int));
    int left = low;
    int right = mid+1;

    int index = 0;
    while(left<=mid && right<=high){
        if(array[left]<=array[right]){
            temp[index++] = array[left];
            left++;
        }
        else{
            temp[index++] = array[right];
            right++;
        }
    }

    while(left<=mid){
        temp[index++] = array[left];
        left++;
    }

    while(right<=high){
        temp[index++] = array[right];
        right++;
    }

    for(int i=low; i<=high; i++){
        array[i] = temp[i-low];
    }

    free(temp);
}

void merge_sort(int* array, int low, int high){
    if(low>=high){
        return;
    }

    int mid = (low+high)/2;

    merge_sort(array, low, mid);
    merge_sort(array, mid+1, high);
    merge(array, low, mid, high);
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

    merge_sort(array, 0, length-1);

    printf("Sorted array is: ");
    for(int i=0; i<length; i++){
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}
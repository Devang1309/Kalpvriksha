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

int partition(int* array, int low, int high){
    int pivot = array[low];
    int left = low;
    int right = high;

    while(left<right){
        while(array[left]<=pivot && left<=high-1){
            left++;
        }

        while(array[right]>=pivot && right>=low+1){
            right--;
        }

        if(left<right){
            int swap = array[left];
            array[left] = array[right];
            array[right] = swap;
        }
    }

    int swap = array[low];
    array[low] = array[right];
    array[right] = swap;

    return right;
}

void quick_sort(int* array, int low, int high){
    if(low<high){
        int partition_index = partition(array, low, high);

        quick_sort(array, low, partition_index-1);
        quick_sort(array, partition_index+1, high);
    }
}

int* quick_sort_function(int* array, int length){
    quick_sort(array, 0, length-1);
    return array;
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

    array = quick_sort_function(array, length);

    printf("Sorted array is: \n");
    for(int i=0; i<length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}
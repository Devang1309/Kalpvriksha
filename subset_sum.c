#include <stdio.h>
#include <stdlib.h>

int subset_sum(int index1, int index2, int* array, int length, int* subset, int target){
    int sum = 0;
    for(int i=0; i<index2; i++){
        sum += subset[i];
    }

    if(sum==target){
        return 1;
    }

    if(index1==length){
        return 0;
    }

    subset[index2] = array[index1];
    if(subset_sum(index1+1, index2+1, array, length, subset, target)) return 1;
    index2--;
    if(subset_sum(index1+1, index2+1, array, length, subset, target)) return 1;

    return 0;
}

int main(){
    int size;
    printf("Enter the size of array: \n");
    scanf("%d", &size);

    int target;
    printf("Enter the target sum: \n");
    scanf("%d", &target);

    int* array = (int*)malloc(size*sizeof(int));
    int data;

    int length = 0;
    printf("Enter the elements of array: \n");
    while(scanf("%d", &data)==1){
        array[length++] = data;
        char ch = getchar();

        if(ch=='\n'){
            break;
        }
    }

    int* subset = (int*)malloc(size*sizeof(int));

    int answer = subset_sum(0, 0, array, length, subset, target);
    
    if(answer==1){
        printf("Yes subset equal to given sum is present");
    }
    else{
        printf("No subset is equal to sum");
    }

    return 0;
}
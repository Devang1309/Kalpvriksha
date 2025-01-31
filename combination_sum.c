#include <stdio.h>
#include <stdlib.h>

int not_found = 0;

void find_combinations(int index, int combination_size, int target, int* array, int length, int* combination){
    if(target==0){
        not_found = 1;
        for(int i=0; i<combination_size; i++){
            printf("%d ", combination[i]);
        }
        printf("\n");
        return;
    }

    if(index==length){
        return;
    }

    if(array[index] <= target){
        combination[combination_size++] = array[index];
        find_combinations(index, combination_size, target-array[index], array, length, combination);
        combination_size--;
    }

    find_combinations(index+1, combination_size, target, array, length, combination);
}

int main(){
    int* array = (int*)malloc(1000*sizeof(int));
    int data;

    int length = 0;
    printf("Enter the elements: ");
    while(scanf("%d", &data)==1){
        array[length++] = data;
        char ch = getchar();
        if(ch=='\n'){
            break;
        }
    }

    int target;
    printf("Enter the target: ");
    scanf("%d", &target);

    int* combination = (int*)malloc(1000*sizeof(int));

    printf("The combinations are: \n");
    find_combinations(0, 0, target, array, length, combination);
    if(not_found==0){
        printf("No possible solutions!");
    }

    return 0;
}
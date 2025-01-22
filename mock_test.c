#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    printf("Enter the size: \n");
    scanf("%d", &size);

    int** matrix = (int**)malloc(size*sizeof(int*));

    for(int i=0; i<size; i++){
        matrix[i] = (int*)malloc(size*sizeof(int));
    }

    printf("Enter the elements: \n");
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Resultant matrix is: \n");

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    return 0;
}
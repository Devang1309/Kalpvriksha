#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_paths(int row, int col, int** matrix, int size, int** visited, char* path, int index){
    if(row==size-1 && col==size-1){
        path[index] = '\0';
        printf("%s\n", path);
        return;
    }

    if(row+1<size && !visited[row+1][col] && matrix[row+1][col]==1){
        visited[row][col] = 1;
        path[index] = 'D';
        find_paths(row+1, col, matrix, size, visited, path, index+1);
        visited[row][col] = 0;
    }

    if(col-1>=0 && !visited[row][col-1] && matrix[row][col-1]==1){
        visited[row][col] = 1;
        path[index] = 'L';
        find_paths(row, col-1, matrix, size, visited, path, index+1);
        visited[row][col] = 0;
    }

    if(col+1<size && !visited[row][col+1] && matrix[row][col+1]==1){
        visited[row][col] = 1;
        path[index] = 'R';
        find_paths(row, col+1, matrix, size, visited, path, index+1);
        visited[row][col] = 0;
    }

    if(row-1>=0 && !visited[row-1][col] && matrix[row-1][col]==1){
        visited[row][col] = 1;
        path[index] = 'U';
        find_paths(row-1, col, matrix, size, visited, path, index+1);
        visited[row][col] = 0;
    }
}

int main(){
    int size;
    printf("Enter the size of the square matrix:\n");
    scanf("%d", &size);

    int** matrix = (int**)malloc(size*sizeof(int*));
    for(int i=0; i<size; i++){
        matrix[i] = (int*)malloc(size*sizeof(int));
    }

    printf("Enter the cells of matrix: \n");
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int** visited = (int**)malloc(size*sizeof(int*));
    for(int i=0; i<size; i++){
        visited[i] = (int*)malloc(size*sizeof(int));
    }

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            visited[i][j] = 0;
        }
    }

    char* path = (char*)malloc(100000*sizeof(char));

    printf("Possible ways from source to destination: \n");
    if(matrix[0][0]==1){
        find_paths(0, 0, matrix, size, visited, path, 0);
    }
    else if(matrix[size-1][size-1]==0 && matrix[0][0]==1){
        printf("Destination is blocked!...No possible ways.");
    }
    else{
        printf("Source is blocked!...No possible ways.\n");
    }

    free(path);
    for(int i=0; i<size; i++){
        free(matrix[i]);
    }
    free(matrix);

    for(int i=0; i<size; i++){
        free(visited[i]);
    }
    free(visited);

    return 0;
}
#include <stdio.h>

int isnumber(int num){
    if(num>=0 && num<=9){
        return 1;
    }
    return 0;
}

void matrixRotation( int col, int matrix[][col], int row){
    int temp[row][col];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            temp[i][j] = matrix[j][i];
        }
    }

    for(int i=0; i<row; i++){
        int start = 0, end = col-1; 
        int swap;
        while(start<=end){
            swap = temp[i][start];
            temp[i][start] = temp[i][end];
            temp[i][end] = swap;
            start++;
            end--;
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            matrix[i][j] = temp[i][j];
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void rowRotation_left(int col, int matrix[][col], int row){
    int rotation;
    printf("Enter the number of times you want to rotate: ");
    scanf("%d", &rotation);
    if(rotation>=col){
        rotation %= col;
    }

    for(int i=0; i<row; i++){
        int swap1;
        int start1=0; int end1=rotation-1;
        while(start1<=end1){
            swap1 = matrix[i][start1];
            matrix[i][start1] = matrix[i][end1];
            matrix[i][end1] = swap1;
            start1++;
            end1--;
        }

        int swap2;
        int start2=rotation; int end2=col-1;
        while(start2<=end2){
            swap2 = matrix[i][start2];
            matrix[i][start2] = matrix[i][end2];
            matrix[i][end2] = swap2;
            start2++;
            end2--;
        }

        int swap;
        int start=0; int end=col-1;
        while(start<=end){
            swap = matrix[i][start];
            matrix[i][start] = matrix[i][end];
            matrix[i][end] = swap;
            start++;
            end--;
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void rowRotation_right(int col, int matrix[][col], int row){
    int rotation;
    printf("Enter the number of times you want to rotate: ");
    scanf("%d", &rotation);
    if(rotation >= col) {
        rotation %= col;  
    }

    for(int i = 0; i < row; i++) {
        int temp[col];
        for(int j = 0; j < col; j++) {
            temp[(j + rotation) % col] = matrix[i][j];  
        }
        for(int j = 0; j < col; j++) {
            matrix[i][j] = temp[j];  
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void colRotation_up(int col, int matrix[][col], int row){
    int rotation;
    printf("Enter the number of times you want to rotate: ");
    scanf("%d", &rotation);
    if(rotation>=row){
        rotation %= row;
    }

    for(int j=0; j<col; j++){
        int swap1;
        int start1=0; int end1=rotation-1;
        while(start1<=end1){
            swap1 = matrix[start1][j];
            matrix[start1][j] = matrix[end1][j];
            matrix[end1][j] = swap1;
            start1++;
            end1--;
        }

        int swap2;
        int start2=rotation; int end2=col-1;
        while(start2<=end2){
            swap2 = matrix[start2][j];
            matrix[start2][j] = matrix[end2][j];
            matrix[end2][j] = swap2;
            start2++;
            end2--;
        }

        int swap;
        int start=0; int end=col-1;
        while(start<=end){
            swap = matrix[start][j];
            matrix[start][j] = matrix[end][j];
            matrix[end][j] = swap;
            start++;
            end--;
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void colRotation_down(int col, int matrix[][col], int row){
    int rotation;
    printf("Enter the number of times you want to rotate: ");
    scanf("%d", &rotation);
    if(rotation >= row) {
        rotation %= row;  
    }

    for(int j = 0; j < col; j++) {
        int temp[row];
        for(int i = 0; i < row; i++) {
            temp[(i + rotation) % row] = matrix[i][j];  
        }
        for(int i = 0; i < row; i++) {
            matrix[i][j] = temp[i];  
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int row, col;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of cols: ");
    scanf("%d", &col);
    int matrix[row][col];

    printf("Enter the elements of matrix(integers): \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &matrix[i][j]);
            if(!isnumber(matrix[i][j])){
                printf("Enter a valid number!");
                return 0;
            }
        }
    }
    printf("\n");

    while(1){
        printf("Enter the operation to perform on matrix:\n");
        printf(" 1. Matrix-Level Rotation\n 2. Row-Wise rotation(Left)\n 3. Row-Wise rotation(Right)\n 4. Column-Wise rotation(Up)\n 5. Column-Wise rotation(Down)\n 6. Exit\n");

        int choice=0;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            matrixRotation(col, matrix, row);
            break;
        
        case 2:
            rowRotation_left(col, matrix, row);
            break;
        
        case 3:
            rowRotation_right(col, matrix, row);
            break;

        case 4:
            colRotation_up(col, matrix, row);
            break;

        case 5:
            colRotation_down(col, matrix, row);
            break;
        
        case 6:
            printf("Exit.");
            return 0;

        default:
            printf("Select a valid option!\n");
            break;
        }
    }

    return 0;
}
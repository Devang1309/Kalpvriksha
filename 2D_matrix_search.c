#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int is_number(char ch){
    return (ch >= '0' && ch <= '9');
}

int string_length(char* sentence){
    int i = 0;
    int length = 0;
    while(sentence[i] != '\0'){
        length++;
        i++;
    }
    return length;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int row = 0;
    int col = matrixColSize[0] - 1; 
    
    while (row < matrixSize && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        } 
        else if (matrix[row][col] > target) {
            col--; 
        } 
        else {
            row++;
        }
    }
    
    return false; 
}

int main() {
    char* sentence = (char*)malloc(100 * sizeof(char));
    printf("Enter the expression: ");
    fgets(sentence, 100, stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; 

    int length = string_length(sentence);

    int row = 0, col = 0;
    int tempCol = 0;
    bool inNumber = false;

    for (int i = 0; i < length; i++) {
        if (sentence[i] == '[') {
            row++;
            tempCol = 0;
        } 
        else if (sentence[i] == ',' && row > 0) {
            tempCol++;
        } 
        else if (sentence[i] == ']') {
            if (tempCol > col) {
                col = tempCol; 
            }
        }
    }

    col++; 

    int target;
    printf("Enter the target: ");
    scanf("%d", &target);

    int** matrix = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(col * sizeof(int));
    }

    int index = 0, negative = 0;
    int* elements = (int*)calloc(row * col, sizeof(int));
    for (int i = 0; i < length; i++) {
        if (is_number(sentence[i])) {
            elements[index] = elements[index] * 10 + (sentence[i] - '0');
        } 
        else if (sentence[i] == ',') {
            if (negative == 1) {
                elements[index] = -elements[index];
                negative = 0;
            }
            index++;
        } 
        else if (sentence[i] == '-') {
            negative = 1;
        }
    }

    int newIndex = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = elements[newIndex++];
        }
    }

    bool found = searchMatrix(matrix, row, &col, target);

    if (found) {
        printf("true");
    } 
    else {
        printf("false");
    }

    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(elements);
    free(sentence);

    return 0;
}

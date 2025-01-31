#include <stdio.h>
#include <stdlib.h>

void construct_board(int column, char** board, char** final_board, int* left_row, int* upper_diagonal,
int* lower_diagonal, int size){
    if(column==size){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                final_board[i][j] = board[i][j];
            }
        }

        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                printf("%c ", final_board[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        return;
    }

    for(int row=0; row<size; row++){
        if(left_row[row]==0 && lower_diagonal[row+column]==0 && upper_diagonal[size-1+column-row]==0){
            board[row][column] = 'Q';
            left_row[row] = 1;
            lower_diagonal[row+column] = 1;
            upper_diagonal[size-1+column-row] = 1;

            construct_board(column+1, board, final_board, left_row, upper_diagonal, lower_diagonal, size);

            board[row][column] = '.';
            left_row[row] = 0;
            lower_diagonal[row+column] = 0;
            upper_diagonal[size-1+column-row] = 0;
        }
    }
}

int main(){
    int size;
    printf("Enter the size of the board: \n");
    scanf("%d", &size);

    char** board = (char**)malloc(size*sizeof(char*));

    for(int i=0; i<size; i++){
        board[i] = (char*)malloc(size*sizeof(char));
    }

    char** final_board = (char**)malloc(size*sizeof(char*));

    for(int i=0; i<size; i++){
        final_board[i] = (char*)malloc(size*sizeof(char));
    }

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            board[i][j] = '.';
            final_board[i][j] = '.';
        }
    }

    int* left_row = (int*)calloc(size, sizeof(int));
    int* upper_diagonal = (int*)calloc(2*size-1, sizeof(int));
    int* lower_diagonal = (int*)calloc(2*size-1, sizeof(int));

    printf("The final boards are: \n");
    construct_board(0, board, final_board, left_row, upper_diagonal, lower_diagonal, size);

    return 0;
}
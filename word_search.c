#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search_next(char** board, char* word, int index, int row_index, int col_index, int row, int col){
    if(index==strlen(word)){
        return 1;
    }

    if(row_index<0 || row_index==row || col_index<0 || col_index==col || board[row_index][col_index]!=word[index]
    || board[row_index][col_index]=='#'){
        return 0;
    }

    char temp = board[row_index][col_index];
    board[row_index][col_index] = '#';

    int top = search_next(board, word, index+1, row_index-1, col_index, row, col);
    int right = search_next(board, word, index+1, row_index, col_index+1, row, col);
    int bottom = search_next(board, word, index+1, row_index+1, col_index, row, col);
    int left = search_next(board, word, index+1, row_index, col_index-1, row, col);

    board[row_index][col_index] = temp;

    int result = top || right || bottom || left;

    return result;
}

int word_search(char** board, char* word, int row, int col){
    int index = 0;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(board[i][j] == word[index]){
                if(search_next(board, word, index, i, j, row, col)){
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main(){
    int row, col;
    printf("Enter the number of words: ");
    scanf("%d", &row);
    printf("Enter the size of the word: ");
    scanf("%d", &col);

    char** board = (char**)malloc(row*sizeof(char*));

    for(int i=0; i<row; i++){
        board[i] = (char*)malloc(col*sizeof(char));
    }
    getchar();

    printf("Enter the letters of the words: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%c", &board[i][j]);
            getchar();
        }
    }

    char* word = (char*)malloc(1000*sizeof(char));
    printf("Enter a word to check: ");
    fgets(word, 1000, stdin);
    word[strcspn(word, "\n")] = '\0';

    int answer = word_search(board, word, row, col);

    if(answer==1){
        printf("True");
    }
    else{
        printf("False");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int scores(int* numbers, int player1_turn, int player1_score, int player2_score, int index1, int index2){
    if(index1>index2){
        if(player1_score>=player2_score){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(player1_turn){
        int result = scores(numbers, 0, player1_score+numbers[index1], player2_score, index1+1, index2) ||
        scores(numbers, 0, player1_score+numbers[index2], player2_score, index1, index2-1);

        return result;
    }

    return scores(numbers, 1, player1_score, player2_score+numbers[index1], index1+1, index2) &&
        scores(numbers, 1, player1_score, player2_score+numbers[index2], index1, index2-1);
}

int main(){
    int* numbers = (int*)malloc(1000*sizeof(int));
    printf("Enter the numbers: \n");
    int index = 0;
    int data;
    while(scanf("%d", &data)==1){
        numbers[index++] = data;
        char ch = getchar();

        if(ch=='\n'){
            break;
        }
    }

    int answer = scores(numbers, 1, 0, 0, 0, index-1);

    if(answer == 1){
        printf("True - Player 1 can win!");
    }
    else{
        printf("False - Player 1 can never win!");
    }

    return 0;
}
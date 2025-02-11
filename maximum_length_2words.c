#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input_sentence(char* sentence[]){
    int index = 0;

    while(1){
        char* word = (char*)malloc(1000*sizeof(char));
        scanf("%s", word);

        sentence[index++] = word;
        char ch = getchar();
        if(ch=='\n' || ch==EOF){
            break;
        }
    }

    return index;
}

int length_word(char* word){
    int size = 0;
    while(word[size]!='\0'){
        size++;
    }
    return size;
}

int not_same(char* word1, char* word2){
    int same = 1;

    int length1 = length_word(word1);
    int length2 = length_word(word2);

    for(int i=0; i<length1; i++){
        for(int j=0; j<length2; j++){
            if(word1[i]==word2[j]){
                same = 0;
            }
        }
    }

    return same;
}

int check_maximum(char* sentence[], int length){
    int result = 0;
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            if(not_same(sentence[i], sentence[j])==0){
                continue;
            }
            else{
                int temp = length_word(sentence[i])*length_word(sentence[j]);
                if(temp>result){
                    result = temp;
                }
            }
        }
    }

    return result;
}

int main(){
    char* sentence[1000];

    int length = input_sentence(sentence);
    int answer = check_maximum(sentence, length);

    printf("Maximum length multiplication is: %d", answer);

    return 0;
}
#include <stdio.h>
#include <string.h>

char lower_case(char ch){
    if(ch>='A' && ch<='Z'){
        ch = ch-'A'+'a';
        return ch;
    }
    else{
        return ch;
    }
}

int  main(){
    char word[100];
    printf("Enter the word: \n");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")]='\0';

    printf("Enter word to replace:\n");

    char replace_word;
    scanf("%c", &replace_word);

    int length = strlen(word);

    for(int i=0; i<length; i++){
        int match = 0;
        for(int j=0; j<length; j++){
            if(i==j){
                continue;
            }
            if(lower_case(word[i])==lower_case(word[j])){
                match++;
            }
        }
        if(match==0 && word[i]!=' '){
            word[i] = replace_word;
            break;
        }
    }

    printf("%s", word);

    return 0;
}
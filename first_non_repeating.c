#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* word = (char*)malloc(1000*sizeof(char));
    fgets(word, 1000, stdin);
    word[strcspn(word, "\n")] = '\0';

    char non_repeating = word[0];
    printf("%c", non_repeating);

    int found = 0;
    int i=1;
    while(word[i]!='\0'){
        if(word[i]==non_repeating){
            printf("-1");
            found = 1;
        }
        else if(word[i]!=non_repeating){
            if(found==1){
                non_repeating=word[i];
                printf("%c", non_repeating);
                found = 0;
            }
            else{
                printf("%c", non_repeating);
            }
        }

        i++;
    }

    return 0;
}
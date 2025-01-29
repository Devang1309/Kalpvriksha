#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(char* first, char* second){
    int index = 0;
    char* new_first = (char*)malloc(1000*sizeof(char));
    int new_index = 0;
    while(first[index]!='\0'){
        if(first[index]=='#'){
            if(new_index>0){
                new_index--;
            }
        }
        else{
            new_first[new_index++] = first[index];
        }

        index++;
    }
    new_first[new_index] = '\0';

    char* new_second = (char*)malloc(1000*sizeof(char));
    new_index = 0;
    index = 0;
    while(second[index]!='\0'){
        if(second[index]=='#'){
            if(new_index>0){
                new_index--;
            }
        }
        else{
            new_second[new_index++] = second[index];
        }

        index++;
    }
    new_second[new_index] = '\0';

    if(strcmp(new_first, new_second)){
        return 0;
    }
    
    return 1;
}

int main(){
    char* first_string = (char*)malloc(1000*sizeof(char));
    char* second_string = (char*)malloc(1000*sizeof(char));

    fgets(first_string, 1000, stdin);
    first_string[strcspn(first_string, "\n")] = '\0';

    fgets(second_string, 1000, stdin);
    second_string[strcspn(second_string, "\n")] = '\0';

    int answer = compare_strings(first_string, second_string);

    if(answer == 1){
        printf("True");
    }
    else{
        printf("False");
    }

    return 0;
}
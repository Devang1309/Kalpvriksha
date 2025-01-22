#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int string_length(char* string){
    int i=0; 
    int length=0;

    while(string[i] != '\0'){
        length++;
        i++;
    }

    return length;
}

int main(){
    char string1[100]; 
    char string2[100]; 

    printf("Enter the first string: ");
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(string2, sizeof(string2), stdin);
    string2[strcspn(string2, "\n")] = '\0';

    if(string_length(string1) != string_length(string2)){
        printf("Strings are not equal! \n");
        return 0;
    }

    int length = string_length(string1);

    int i=0, j=0;
    while(string1[i] != '\0'){
        int not_matched = 0; j=0;
        while(string2[j] !='\0'){
            if(string1[i] == string2[j]){
                break;
            }
            else{
                not_matched++;
                j++;
            }
        }

        if(not_matched == length){
            printf("Strings can't be equal!\n");
            return 0;
        }
        i++;
    }

    printf("Strings can be equal!\n");
    return 0;
}
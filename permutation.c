#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int spaces(char* str){
    int index=0;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            index++;
        }
        i++;
    }

    return index;
}

int stringLength(char* str){
    int index=0;
    int i=0;
    while(str[i]!='\0'){
        index++;
        i++;
    }

    return index; 
}

void swap(char *str1, char *str2) {
    char temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void permute(char *str, int start_index, int end_index) {
    int i;
    if (start_index == end_index) {
        printf("%s", str);
    } 
    else {
        for (i = start_index; i <= end_index; i++) {
            swap((str + start_index), (str + i));  
            permute(str, start_index + 1, end_index);    
            swap((str + start_index), (str + i));  
        }
    }
}

int main() {
    char *str = (char *)malloc(100 * sizeof(char));    

    if (str == NULL) {  
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    int len = stringLength(str); 

    int spacesCount = spaces(str);

    if(len==0 || spacesCount==len){
        printf("Enter a valid string!");
        return 0;
    } 

    permute(str, 0, len - 1);

    free(str);

    return 0;
}

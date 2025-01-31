#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_combinations(char* digits, char* output, int output_index, int index, char* mapping[11]){
    if(index >= strlen(digits)){
        output[output_index] = '\0';
        printf("%s\n", output);
        return;
    }

    int number = digits[index] - '0';
    char* value = mapping[number];

    for(int i=0; i<strlen(value); i++){
        output[output_index++] = value[i];
        print_combinations(digits, output, output_index, index+1, mapping);
        output_index--;
    }
}

void letter_combination(char* digits){
    if(strlen(digits)==0){
        printf("\n");
    }

    char* mapping[11] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int index = 0;
    char* output = (char*)malloc(100*sizeof(char));

    print_combinations(digits, output, 0, index, mapping);
}

int main(){
    char* digits = (char*)malloc(100*sizeof(char));
    printf("Enter the number: ");
    fgets(digits, 100, stdin);
    digits[strcspn(digits, "\n")] = '\0';

    letter_combination(digits);

    return 0;
}
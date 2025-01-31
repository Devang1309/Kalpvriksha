#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_parentheses(char* operation, int open, int close, int index) {
    if (open == 0 && close == 0) {
        operation[index] = '\0';  
        printf("%s\n", operation);  
        return;
    }

    if (open > 0) {
        operation[index] = '(';
        generate_parentheses(operation, open - 1, close, index + 1);
    }

    if (close > open) {
        operation[index] = ')';
        generate_parentheses(operation, open, close - 1, index + 1);
    }
}

int main() {
    int pairs;
    printf("Enter the number of pairs: \n");
    scanf("%d", &pairs);

    char* operation = (char*)malloc((2 * pairs + 1)*sizeof(char)); 

    printf("All possible sequences of parentheses are:\n");
    generate_parentheses(operation, pairs, pairs, 0);

    free(operation);  

    return 0;
}

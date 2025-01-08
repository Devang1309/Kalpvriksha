#include <stdio.h>
#include <string.h>
#include <ctype.h>

char newToLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int startsWithVowel(char *name) {
    char firstChar = newToLower(name[0]);
    return (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u');
}

int stringLength(char *str) {
    int length = 0;
    while(str[length++] != '\0');
    return length;
}

int main() {
    int rows, cols;
    char names[10][10][51]; 
    int vowelCount = 0;
    char longestName[51] = "";

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    if (rows < 1 || rows > 10) {
        printf("Invalid number of rows!\n");
        return 1;
    }

    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    if (cols < 1 || cols > 101) {
        printf("Invalid number of columns!\n");
        return 1;
    }

    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);
            while(getchar()!='\n');
            
            if (startsWithVowel(names[i][j])) {
                vowelCount++;
            }
            
            if(stringLength(names[i][j]) >= 51){
                printf("Names with smaller length are only allowed!");
                return 0;
            }

            if (stringLength(names[i][j]) > stringLength(longestName)) {
                strcpy(longestName, names[i][j]);
            }
        }
    }

    printf("\nThe 2D array of names is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }

    printf("\nNumber of names starting with a vowel: %d\n", vowelCount);
    printf("The longest name: %s\n", longestName);

    return 0;
}

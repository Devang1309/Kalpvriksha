#include <stdio.h>
#include <string.h>

int isPalindrome(char s[], int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

void printPartitions(char string[1000], int start, int end, char partitions[][100], int index) {
    if (start == end) {
        for (int i = 0; i < index; i++) {
            printf("%s", partitions[i]);
            if (i < index - 1) {
                printf(", ");
            }
        }
        printf("\n");
        return;
    }

    for (int i = start; i < end; i++) {
        if (isPalindrome(string, start, i)) {
            strncpy(partitions[index], string + start, i - start + 1);
            partitions[index][i - start + 1] = '\0'; 
            index++;

            printPartitions(string, i + 1, end, partitions, index);
            index--;
        }
    }
}

int main() {
    char string[1000];
    
    printf("Enter the string: \n");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0'; 

    int length = strlen(string);
    char partitions[100][100]; 
    int index = 0; 

    printf("Strings after palindrome partitionings are:\n");
    printPartitions(string, 0, length, partitions, index);

    return 0;
}

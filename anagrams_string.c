#include <stdio.h>
#include <string.h>

void copy_string(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  
}

int string_length(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void sort_string(char *str) {
    int len = string_length(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int compare_strings(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;  
        }
        i++;
    }
    return str1[i] == str2[i];  
}

void groupAnagrams(char strs[][101], int strsSize) {
    int grouped = 0; 

    int groupedFlags[strsSize];
    for (int i = 0; i < strsSize; i++) {
        groupedFlags[i] = 0;  
    }

    printf("Groups of Anagrams are: \n");

    for (int i = 0; i < strsSize; i++) {
        if (groupedFlags[i]) {
            continue;  
        }

        int firstSortedStringIndex = i;
        printf("%s", strs[firstSortedStringIndex]);
        groupedFlags[firstSortedStringIndex] = 1;

        for (int j = i + 1; j < strsSize; j++) {
            if (!groupedFlags[j]) {
                char sortedStr1[101], sortedStr2[101];
                
                copy_string(sortedStr1, strs[i]);  
                copy_string(sortedStr2, strs[j]);  

                sort_string(sortedStr1);  
                sort_string(sortedStr2);  

                if (compare_strings(sortedStr1, sortedStr2)) {
                    printf(", %s", strs[j]);
                    groupedFlags[j] = 1;  
                }
            }
        }
        printf("\n");
        grouped++;
    }

    if (grouped == 0) {
        printf("No groups formed!\n");
    }
}

int main() {
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char strs[n][101]; 

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", strs[i]);  
    }

    groupAnagrams(strs, n);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int string_length(char str[1000]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void string_copy(char dest[1000], char src[1000]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
}

void countAndSayHelper(char str[1000], char result[1000]) {
    int i = 0, j = 0;
    int len = string_length(str);  
    
    while (i < len) {
        int count = 1;
        while (i + 1 < len && str[i] == str[i + 1]) {
            i++;
            count++;
        }
        
        result[j++] = count + '0'; 
        result[j++] = str[i];
        
        i++;
    }

    result[j] = '\0';
}

void countAndSay(int final) {
    char current[1000] = "1"; 
    char result[1000];
    
    for (int i = 2; i <= final; i++) {
        countAndSayHelper(current, result);  
        string_copy(current, result);  
    }
    
    printf("%s", current);
}

int main() {
    int n;

    printf("Enter no. of iterations: ");
    scanf("%d", &n);

    countAndSay(n);
    
    return 0;
}

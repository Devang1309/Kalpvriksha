#include <stdio.h>
#include <string.h>
#include <limits.h>

int findSecondLargestWordIndex(int lengths[], int count) {
    int firstMax = INT_MIN, secondMax = INT_MIN;
    int firstIndex = -1, secondIndex = -1;

    for (int i = 0; i < count; i++) {
        if (lengths[i] > firstMax) {
            secondMax = firstMax;
            secondIndex = firstIndex;
            firstMax = lengths[i];
            firstIndex = i;
        } 
		else if (lengths[i] > secondMax && lengths[i] != firstMax) {
            secondMax = lengths[i];
            secondIndex = i;
        }
    }
    return secondIndex;
}

int main() {
    char sentence[100];
    int lengths[100] = {0};
    int index = 0, wordLength = 0, wordCount = 0;
    
    printf("Enter the sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    while (sentence[index] != '\0') {
        if (sentence[index] == ' ') {
            if (wordLength > 0) {
                lengths[wordCount++] = wordLength;
                wordLength = 0;
            }
        } 
		else {
            wordLength++;
        }
        index++;
    }
    if (wordLength > 0) {
        lengths[wordCount++] = wordLength;
    }

    int secondLargestIndex = findSecondLargestWordIndex(lengths, wordCount);

    if (secondLargestIndex == -1 && wordCount <= 1) {
        printf("There is no second largest word!\n");
    } 
    else if(secondLargestIndex == -1 && wordCount >= 1){
        int i=0;
        while(sentence[i]!=' '){
            printf("%c", sentence[i]);
            i++;
        }
    }
	else {
        int start = 0, count = 0;
        for (int i = 0; sentence[i] != '\0'; i++) {
            if (sentence[i] == ' ' || sentence[i + 1] == '\0') {
                if (count == secondLargestIndex) {
                    if (sentence[i + 1] == '\0') i++;
                    for (int j = start; j < i; j++) {
                        printf("%c", sentence[j]);
                    }
                    break;
                }
                start = i + 1;
                count++;
            }
        }
        printf("\n");
    }

    return 0;
}

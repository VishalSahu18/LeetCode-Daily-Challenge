typedef struct {
    char word[101];
    int count;
} WordCount;

void storeString(WordCount *countArr, int *size, char *s) {
    char *token = strtok(s, " ");
    while (token != NULL) {
        bool found = false;
        for (int i = 0; i < *size; i++) {
            if (strcmp(countArr[i].word, token) == 0) {
                countArr[i].count++;
                found = true;
                break;
            }
        }
        if (!found) {
            strcpy(countArr[*size].word, token);
            countArr[*size].count = 1;
            (*size)++;
        }
        token = strtok(NULL, " ");
    }
}

char** uncommonFromSentences(char* s1, char* s2, int* returnSize) {
    WordCount countArr[200];  
    int size = 0;
    *returnSize = 0;          

    char *dup1 = strdup(s1);
    char *dup2 = strdup(s2);

    storeString(countArr, &size, dup1);
    storeString(countArr, &size, dup2);

    char** result = (char**)malloc(200 * sizeof(char*));

    for (int i = 0; i < size; i++) {
        if (countArr[i].count == 1) {
            result[*returnSize] = strdup(countArr[i].word);
            (*returnSize)++;
        }
    }

    free(dup1);
    free(dup2);
    return result;

}
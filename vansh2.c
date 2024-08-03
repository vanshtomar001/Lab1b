#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int find_word(char words[MAX_WORDS][MAX_WORD_LEN], int count, char *word) {
    for (int i = 0; i < count; i++) {
        if (strcmp(words[i], word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char paragraph[1000];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int counts[MAX_WORDS] = {0};
    int word_count = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " ,.!?;\n");

    while (token != NULL) {
        to_lowercase(token);
        int index = find_word(words, word_count, token);
        if (index != -1) {
            counts[index]++;
        } else {
            strcpy(words[word_count], token);
            counts[word_count] = 1;
            word_count++;
        }
        token = strtok(NULL, " ,.!?;\n");
    }

    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }

    return 0;
}

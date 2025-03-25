#include <stdio.h>
#include <string.h>

const char* keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "int", "long",
    "register", "return", "short", "signed", "sizeof", "static", "struct",
    "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

int isKeyword(const char* word) {
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char word[20];
    printf("Enter a word: ");
    scanf("%s", word);
    if (isKeyword(word)) {
        printf("'%s' is a valid keyword.\n", word);
    } else {
        printf("'%s' is NOT a valid keyword.\n", word);
    }
    return 0;
}

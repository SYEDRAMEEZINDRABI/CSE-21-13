#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidIdentifier(const char* str) {
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0;
    }
    for (int i = 1; i < strlen(str); i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[50];
    printf("Enter a string: ");
    scanf("%s", input);
    if (isValidIdentifier(input)) {
        printf("'%s' is a valid identifier.\n", input);
    } else {
        printf("'%s' is NOT a valid identifier.\n", input);
    }
    return 0;
}

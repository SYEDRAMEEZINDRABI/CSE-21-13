#include <stdio.h>

int main() {
    char filename[100];
    FILE *file;
    int count = 0;
    char ch;

    printf("Enter the name of the program file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s.\n", filename);
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    fclose(file);
    printf("Number of lines in the program: %d\n", count);

    return 0;
}

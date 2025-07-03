#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char ch;
    char data[100];

    // 1. Create and write to a file
    file = fopen("example.txt", "w");  // "w" mode creates or overwrites
    if (file == NULL) {
        printf("Unable to create file.\n");
        return 1;
    }
    fprintf(file, "This is the first line.\n");
    fclose(file);
    printf("File created and data written successfully.\n");

    // 2. Read from the file
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Unable to open file for reading.\n");
        return 1;
    }
    printf("\nReading file content:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);

    // 3. Append data to the file
    file = fopen("example.txt", "a");  // "a" mode appends to file
    if (file == NULL) {
        printf("Unable to open file for appending.\n");
        return 1;
    }
    fprintf(file, "This is an appended line.\n");
    fclose(file);
    printf("\nData appended successfully.\n");

    // 4. Read updated content
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }
    printf("\nUpdated file content:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);

    return 0;
}

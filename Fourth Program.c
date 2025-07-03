#include <stdio.h>
#include <string.h>

void runLengthEncode(char *input) {
    int len = strlen(input);
    int count = 1;

    for (int i = 0; i < len; i++) {
        // Count occurrences of current character
        while (i < len - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        // Print current character and its count
        printf("%c%d", input[i], count);
        count = 1; // Reset count for next character
    }

    printf("\n");
}

int main() {
    char str[100];

    printf("Enter a string to compress (no spaces): ");
    scanf("%s", str);

    printf("Compressed string using Run-Length Encoding: ");
    runLengthEncode(str);

    return 0;
}

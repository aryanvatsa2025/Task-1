#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char keywords[][10] = {
    "int", "float", "if", "else", "while", "for", "return", "void", "char"
};

char operators[] = "+-*/=%<>&|!";

int isKeyword(char *word) {
    for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[50];
    int i = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    printf("Lexical Analysis Output:\n");

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) {
            buffer[i++] = ch;
        } else {
            if (i > 0) {
                buffer[i] = '\0';
                if (isKeyword(buffer))
                    printf("[Keyword]    : %s\n", buffer);
                else
                    printf("[Identifier] : %s\n", buffer);
                i = 0;
            }

            if (isOperator(ch)) {
                printf("[Operator]   : %c\n", ch);
            }
        }
    }

    fclose(fp);
    return 0;
}

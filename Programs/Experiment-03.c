/* Experiment 3: Ignore spaces, tabs, newlines and comments while scanning tokens. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int is_keyword(const char *word) {
    static const char *keywords[] = {
        "main","auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for","goto","if",
        "int","long","register","return","short","signed","sizeof","static",
        "struct","switch","typedef","unsigned","void","printf","while"
    };
    for (size_t i = 0; i < sizeof keywords / sizeof keywords[0]; i++)
        if (strcmp(word, keywords[i]) == 0) return 1;
    return 0;
}

int main(void) {
    FILE *fp = fopen("flex_input.txt", "r");
    int ch;
    char word[128];
    size_t n = 0;
    if (!fp) {
        perror("flex_input.txt");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '/') {
            int next = fgetc(fp);
            if (next == '/') {
                while ((ch = fgetc(fp)) != EOF && ch != '\n') {}
                continue;
            } else if (next == '*') {
                int prev = 0;
                while ((ch = fgetc(fp)) != EOF) {
                    if (prev == '*' && ch == '/') break;
                    prev = ch;
                }
                continue;
            } else {
                if (next != EOF) ungetc(next, fp);
                puts("/ is operator");
                continue;
            }
        }

        if (isalnum((unsigned char)ch) || ch == '_') {
            if (n < sizeof word - 1) word[n++] = (char)ch;
        } else {
            if (n) {
                word[n] = '\0';
                printf("%s is %s\n", word, is_keyword(word) ? "keyword" : "identifier");
                n = 0;
            }
            if (strchr("+-*%=", ch)) printf("%c is operator\n", ch);
        }
    }
    if (n) {
        word[n] = '\0';
        printf("%s is %s\n", word, is_keyword(word) ? "keyword" : "identifier");
    }
    fclose(fp);
    return 0;
}

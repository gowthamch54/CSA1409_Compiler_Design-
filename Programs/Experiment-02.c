/* Experiment 2: Check whether a line is a C comment. */
#include <stdio.h>
#include <string.h>

int main(void) {
    char line[256];
    size_t len;
    printf("Enter comment: ");
    if (!fgets(line, sizeof line, stdin)) return 1;

    len = strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
        line[--len] = '\0';

    if (strncmp(line, "//", 2) == 0) {
        puts("It is a comment");
    } else if (len >= 4 && strncmp(line, "/*", 2) == 0 &&
               strcmp(line + len - 2, "*/") == 0) {
        puts("It is a comment");
    } else {
        puts("It is not a comment");
    }
    return 0;
}

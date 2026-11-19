/* Experiment 10: Left-factor a production with alternatives.
   Example input: iEtS|iEtSeS|a */
#include <stdio.h>
#include <string.h>

int main(void) {
    char grammar[256], alternatives[20][80], prefix[80];
    int count = 0;
    printf("Enter alternatives for S (example iEtS|iEtSeS|a): ");
    if (scanf("%255s", grammar) != 1) return 1;

    char *part = strtok(grammar, "|");
    while (part && count < 20) {
        strcpy(alternatives[count++], part);
        part = strtok(NULL, "|");
    }
    if (count < 2) {
        puts("At least two alternatives are required.");
        return 0;
    }

    size_t common = strlen(alternatives[0]);
    for (int i = 1; i < count; i++) {
        size_t j = 0;
        while (j < common && alternatives[0][j] == alternatives[i][j]) j++;
        common = j;
    }
    if (common == 0) {
        puts("No common prefix found; no left factoring is needed.");
        return 0;
    }
    memcpy(prefix, alternatives[0], common);
    prefix[common] = '\0';
    printf("S->%sX\nX->", prefix);
    for (int i = 0; i < count; i++) {
        const char *suffix = alternatives[i] + common;
        printf("%s%s", *suffix ? suffix : "$", i == count - 1 ? "\n" : "|");
    }
    return 0;
}

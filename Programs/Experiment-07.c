/* Experiment 7: Find FIRST sets. Use $ to represent epsilon. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char productions[20][40];
int count;
char result[40];
int visiting[26];

static void add(char c) {
    if (!strchr(result, c)) {
        size_t n = strlen(result);
        result[n] = c;
        result[n + 1] = '\0';
    }
}

static void first(char symbol) {
    if (!isupper((unsigned char)symbol)) {
        add(symbol);
        return;
    }
    int index = symbol - 'A';
    if (visiting[index]) return;
    visiting[index] = 1;

    for (int p = 0; p < count; p++) {
        if (productions[p][0] != symbol || productions[p][1] != '=') continue;
        int all_epsilon = 1;
        for (int j = 2; productions[p][j] != '\0'; j++) {
            char before[40];
            strcpy(before, result);
            first(productions[p][j]);
            int has_epsilon = strchr(result, '$') != NULL;
            (void)before;
            if (!has_epsilon) {
                all_epsilon = 0;
                break;
            }
        }
        if (all_epsilon) add('$');
    }
    visiting[index] = 0;
}

int main(void) {
    char symbol, again = 'y';
    printf("How many productions? ");
    if (scanf("%d", &count) != 1 || count < 1 || count > 20) return 1;
    for (int i = 0; i < count; i++) {
        printf("Enter production %d (example S=Aa): ", i + 1);
        scanf("%39s", productions[i]);
    }
    do {
        memset(result, 0, sizeof result);
        memset(visiting, 0, sizeof visiting);
        printf("Find FIRST of: ");
        scanf(" %c", &symbol);
        first(symbol);
        printf("FIRST(%c) = { ", symbol);
        for (size_t i = 0; i < strlen(result); i++) printf("%c ", result[i]);
        puts("}");
        printf("Continue (y/n)? ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');
    return 0;
}

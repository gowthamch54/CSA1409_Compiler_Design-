/* Experiment 8: Find FOLLOW sets for grammars with single-character symbols.
   Use $ for epsilon and enter productions like S=AaAb. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[20][40];
int n;
char follow_set[26][40];
int changed;

static void add_follow(char nt, char c) {
    char *set = follow_set[nt - 'A'];
    if (!strchr(set, c)) {
        size_t len = strlen(set);
        set[len] = c;
        set[len + 1] = '\0';
        changed = 1;
    }
}

static void first_of_sequence(const char *s, char *out) {
    out[0] = '\0';
    if (!*s) return;
    if (!isupper((unsigned char)*s)) {
        if (*s != '$') { out[0] = *s; out[1] = '\0'; }
        return;
    }
    for (int p = 0; p < n; p++) {
        if (prod[p][0] == *s && prod[p][1] == '=') {
            char c = prod[p][2];
            if (c == '$') {
                if (!strchr(out, '$')) { size_t z = strlen(out); out[z] = '$'; out[z + 1] = '\0'; }
            } else if (!strchr(out, c)) {
                size_t k = strlen(out); out[k] = c; out[k+1] = '\0';
            }
        }
    }
}

int main(void) {
    char target, again = 'y';
    printf("Enter total number of productions: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 20) return 1;
    for (int i = 0; i < n; i++) {
        printf("Production %d: ", i + 1);
        scanf("%39s", prod[i]);
    }

    do {
        memset(follow_set, 0, sizeof follow_set);
        add_follow(prod[0][0], '$');

        do {
            changed = 0;
            for (int p = 0; p < n; p++) {
                char lhs = prod[p][0];
                for (int j = 2; prod[p][j] != '\0'; j++) {
                    char b = prod[p][j];
                    if (!isupper((unsigned char)b)) continue;
                    char first[40];
                    first_of_sequence(prod[p] + j + 1, first);
                    for (size_t k = 0; first[k]; k++)
                        if (first[k] != '$') add_follow(b, first[k]);
                    if (prod[p][j + 1] == '\0' || strchr(first, '$'))
                        for (size_t k = 0; follow_set[lhs-'A'][k]; k++)
                            add_follow(b, follow_set[lhs-'A'][k]);
                }
            }
        } while (changed);

        printf("Find FOLLOW of: ");
        scanf(" %c", &target);
        printf("FOLLOW(%c) = { ", target);
        for (size_t i = 0; follow_set[target-'A'][i]; i++)
            printf("%c ", follow_set[target-'A'][i]);
        puts("}");
        printf("Continue (y/n)? ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');
    return 0;
}

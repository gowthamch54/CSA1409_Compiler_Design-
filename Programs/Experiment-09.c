/* Experiment 9: Eliminate immediate left recursion from one production.
   Enter alternatives separated by |, e.g. L->L,S|S */
#include <stdio.h>
#include <string.h>

int main(void) {
    char production[256], lhs, *rhs, *alt;
    char alpha[20][80], beta[20][80];
    int ac = 0, bc = 0;

    printf("Enter production (example L->L,S|S): ");
    if (scanf("%255s", production) != 1) return 1;
    lhs = production[0];
    rhs = strstr(production, "->");
    if (!rhs) { puts("Invalid production format"); return 1; }
    rhs += 2;

    for (alt = strtok(rhs, "|"); alt; alt = strtok(NULL, "|")) {
        if (alt[0] == lhs) {
            if (alt[1] != '\0') strcpy(alpha[ac++], alt + 1);
        } else {
            strcpy(beta[bc++], alt);
        }
    }

    if (ac == 0) {
        puts("The production is not immediately left recursive.");
        return 0;
    }
    if (bc == 0) {
        puts("Cannot apply the standard transformation: no beta alternative.");
        return 0;
    }

    printf("Grammar without left recursion:\n%c->", lhs);
    for (int i = 0; i < bc; i++)
        printf("%s%c'%c", beta[i], lhs, i == bc - 1 ? '\n' : '|');
    printf("%c'->", lhs);
    for (int i = 0; i < ac; i++)
        printf("%s%c'%s", alpha[i], lhs, i == ac - 1 ? "|$" : "|");
    puts("");
    return 0;
}

/* Experiment 12: Recursive descent parser.
   Grammar: E->TE', E'->+TE'|epsilon, T->FT', T'->*FT'|epsilon, F->(E)|id
   Single alphabetic characters are treated as identifiers. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char input[256];
size_t pos = 0;

int E(void);
int T(void);
int F(void);

int E(void) {
    if (!T()) return 0;
    while (input[pos] == '+') {
        pos++;
        if (!T()) return 0;
    }
    return 1;
}
int T(void) {
    if (!F()) return 0;
    while (input[pos] == '*') {
        pos++;
        if (!F()) return 0;
    }
    return 1;
}
int F(void) {
    if (input[pos] == '(') {
        pos++;
        if (!E() || input[pos] != ')') return 0;
        pos++;
        return 1;
    }
    if (isalpha((unsigned char)input[pos])) {
        pos++;
        return 1;
    }
    return 0;
}
int main(void) {
    printf("Enter the string to be checked: ");
    if (scanf("%255s", input) != 1) return 1;
    pos = 0;
    if (E() && input[pos] == '\0') puts("String is accepted");
    else puts("String is not accepted");
    return 0;
}

/* Experiment 15: Operator-precedence expression parser.
   Accepts identifiers i, +, -, *, /, ^ and parentheses. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[256];
int pos = 0;

int expression(void);
int term(void);
int power(void);
int factor(void);

int factor(void) {
    if (input[pos] == '(') {
        pos++;
        if (!expression() || input[pos] != ')') return 0;
        pos++;
        return 1;
    }
    if (input[pos] == 'i' || isalpha((unsigned char)input[pos])) {
        while (isalnum((unsigned char)input[pos])) pos++;
        return 1;
    }
    return 0;
}
int power(void) {
    if (!factor()) return 0;
    if (input[pos] == '^') { pos++; return power(); }
    return 1;
}
int term(void) {
    if (!power()) return 0;
    while (input[pos] == '*' || input[pos] == '/') {
        pos++;
        if (!power()) return 0;
    }
    return 1;
}
int expression(void) {
    if (!term()) return 0;
    while (input[pos] == '+' || input[pos] == '-') {
        pos++;
        if (!term()) return 0;
    }
    return 1;
}
int main(void) {
    printf("Enter the string: ");
    if (scanf("%255s", input) != 1) return 1;
    pos = 0;
    puts(expression() && input[pos] == '\0' ? "Accepted" : "Not Accepted");
    return 0;
}

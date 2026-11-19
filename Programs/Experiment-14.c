/* Experiment 14: Shift-reduce parser for E->E+E | E-E | E*E | E/E | (E) | a.
   Demonstrates shift/reduce actions using a simple expression parser. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[256], stack[512];
int top = -1;

static void show(const char *action) {
    stack[top + 1] = '\0';
    printf("%-20s %-20s %s\n", stack, input, action);
}
int main(void) {
    printf("Enter expression (single-letter operands): ");
    if (scanf("%255s", input) != 1) return 1;
    puts("\nSTACK                INPUT                ACTION");
    for (size_t i = 0; input[i]; i++) {
        stack[++top] = input[i];
        memmove(input, input + 1, strlen(input));
        show("Shift");
        if (isalpha((unsigned char)stack[top])) {
            stack[top] = 'E';
            show("E -> id");
        }
        if (top >= 2 && stack[top-2] == 'E' && strchr("+-*/", stack[top-1]) && stack[top] == 'E') {
            char op = stack[top-1];
            top -= 2;
            stack[top] = 'E';
            char action[32];
            snprintf(action, sizeof action, "E -> E%cE", op);
            show(action);
        }
        if (top >= 2 && stack[top-2] == '(' && stack[top-1] == 'E' && stack[top] == ')') {
            top -= 2; stack[top] = 'E'; show("E -> (E)");
        }
    }
    stack[top + 1] = '\0';
    if (strcmp(stack, "E") == 0) puts("ACCEPT");
    else puts("REJECT");
    return 0;
}

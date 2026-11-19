/* Experiment 18: Simple backend code generation for three-address statements.
   Enter statements such as a=b+c, one per line, then enter END. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char line[128], lhs, a, op, b;
    int reg = 0;
    puts("Enter three-address statements (example a=b+c). Enter END to finish:");
    while (fgets(line, sizeof line, stdin)) {
        if (strncmp(line, "END", 3) == 0) break;
        if (sscanf(line, " %c = %c %c %c", &lhs, &a, &op, &b) == 4) {
            printf("MOV %c, R%d\n", a, reg);
            switch (op) {
                case '+': puts("ADD"); printf("ADD %c, R%d\n", b, reg); break;
                case '-': printf("SUB %c, R%d\n", b, reg); break;
                case '*': printf("MUL %c, R%d\n", b, reg); break;
                case '/': printf("DIV %c, R%d\n", b, reg); break;
                default: puts("Unsupported operator"); continue;
            }
            printf("MOV R%d, %c\n", reg, lhs);
            reg++;
        } else {
            puts("Invalid statement. Expected format: a=b+c");
        }
    }
    return 0;
}

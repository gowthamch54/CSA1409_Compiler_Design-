/* Experiment 4: Recognize arithmetic, relational and logical operators. */
#include <stdio.h>
#include <string.h>

int main(void) {
    char op[8];
    printf("Enter any operator: ");
    if (scanf("%7s", op) != 1) return 1;

    if (!strcmp(op, ">")) puts("Greater than");
    else if (!strcmp(op, ">=")) puts("Greater than or equal");
    else if (!strcmp(op, "<")) puts("Less than");
    else if (!strcmp(op, "<=")) puts("Less than or equal");
    else if (!strcmp(op, "==")) puts("Equal to");
    else if (!strcmp(op, "=")) puts("Assignment");
    else if (!strcmp(op, "!=")) puts("Not Equal");
    else if (!strcmp(op, "!")) puts("Logical NOT");
    else if (!strcmp(op, "&&")) puts("Logical AND");
    else if (!strcmp(op, "&")) puts("Bitwise AND");
    else if (!strcmp(op, "||")) puts("Logical OR");
    else if (!strcmp(op, "|")) puts("Bitwise OR");
    else if (!strcmp(op, "+")) puts("Addition");
    else if (!strcmp(op, "-")) puts("Subtraction");
    else if (!strcmp(op, "*")) puts("Multiplication");
    else if (!strcmp(op, "/")) puts("Division");
    else if (!strcmp(op, "%")) puts("Modulus");
    else puts("Not an operator");
    return 0;
}

/* Experiment 1: Identify identifiers, integer constants and operators. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char input[256], identifiers[100][32], operators[100];
    int constants[100], id_count = 0, const_count = 0, op_count = 0;

    printf("Enter the string: ");
    if (!fgets(input, sizeof input, stdin)) return 1;

    for (int i = 0; input[i] != '\0'; ) {
        if (isspace((unsigned char)input[i])) {
            i++;
        } else if (isalpha((unsigned char)input[i]) || input[i] == '_') {
            int j = 0;
            while (isalnum((unsigned char)input[i]) || input[i] == '_') {
                if (j < 31) identifiers[id_count][j++] = input[i];
                i++;
            }
            identifiers[id_count++][j] = '\0';
        } else if (isdigit((unsigned char)input[i])) {
            int value = 0;
            while (isdigit((unsigned char)input[i])) {
                value = value * 10 + (input[i++] - '0');
            }
            constants[const_count++] = value;
        } else {
            if (strchr("+-*/=%", input[i]) != NULL)
                operators[op_count++] = input[i];
            i++;
        }
    }

    printf("Identifiers: ");
    for (int i = 0; i < id_count; i++) printf("%s ", identifiers[i]);
    printf("\nConstants: ");
    for (int i = 0; i < const_count; i++) printf("%d ", constants[i]);
    printf("\nOperators: ");
    for (int i = 0; i < op_count; i++) printf("%c ", operators[i]);
    printf("\n");
    return 0;
}

/* Experiment 16: Generate three-address code for a + and - expression.
   Input example: out = in1 + in2 + in3 - in4 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char line[256], lhs[32], token[32];
    char operands[40][32], operators[40];
    int n = 0, m = 0;
    printf("Enter assignment: ");
    if (!fgets(line, sizeof line, stdin)) return 1;

    char *eq = strchr(line, '=');
    if (!eq) { puts("Invalid assignment"); return 1; }
    *eq = '\0';
    if (sscanf(line, "%31s", lhs) != 1) return 1;

    char *p = eq + 1;
    while (*p) {
        while (isspace((unsigned char)*p)) p++;
        if (!*p) break;
        if (isalpha((unsigned char)*p) || *p == '_' || isdigit((unsigned char)*p)) {
            int k = 0;
            while (isalnum((unsigned char)*p) || *p == '_') {
                if (k < 31) token[k++] = *p;
                p++;
            }
            token[k] = '\0';
            strcpy(operands[n++], token);
        } else if (*p == '+' || *p == '-') {
            operators[m++] = *p++;
        } else {
            puts("Only + and - operators are supported.");
            return 1;
        }
    }
    if (n != m + 1 || n == 0) { puts("Invalid expression"); return 1; }

    char current[32];
    strcpy(current, operands[0]);
    for (int i = 0; i < m; i++) {
        char temp[32];
        snprintf(temp, sizeof temp, "t%d", i + 1);
        printf("%s=%s%c%s\n", temp, current, operators[i], operands[i+1]);
        strcpy(current, temp);
    }
    printf("%s=%s\n", lhs, current);
    return 0;
}

/* Experiment 6: Validate a C identifier. */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char id[128];
    int valid = 1;
    printf("Enter an identifier: ");
    if (scanf("%127s", id) != 1) return 1;

    if (!(isalpha((unsigned char)id[0]) || id[0] == '_')) valid = 0;
    for (int i = 1; id[i] != '\0'; i++)
        if (!(isalnum((unsigned char)id[i]) || id[i] == '_')) valid = 0;

    puts(valid ? "Valid identifier" : "Not a valid identifier");
    return 0;
}

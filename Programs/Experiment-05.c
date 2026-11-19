/* Experiment 5: Count words, newline characters and non-whitespace characters. */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch, in_word = 0, words = 0, lines = 0, characters = 0;
    printf("Enter text (finish with ~):\n");

    while ((ch = getchar()) != EOF && ch != '~') {
        if (ch == '\n') lines++;
        if (!isspace((unsigned char)ch)) characters++;

        if (isspace((unsigned char)ch)) in_word = 0;
        else if (!in_word) {
            words++;
            in_word = 1;
        }
    }
    printf("Total number of words: %d\n", words);
    printf("Total number of lines: %d\n", lines);
    printf("Total number of characters: %d\n", characters);
    return 0;
}

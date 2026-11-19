/* Experiment 17: Count characters, words and lines in a file.
   Run: ./Experiment-17 input.txt (or enter a filename when prompted). */
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char filename[256];
    FILE *fp;
    int ch, in_word = 0, words = 0, lines = 0, characters = 0;

    if (argc >= 2) snprintf(filename, sizeof filename, "%s", argv[1]);
    else {
        printf("Enter file name: ");
        if (scanf("%255s", filename) != 1) return 1;
    }
    fp = fopen(filename, "r");
    if (!fp) { perror(filename); return 1; }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') lines++;
        if (!isspace((unsigned char)ch)) characters++;
        if (isspace((unsigned char)ch)) in_word = 0;
        else if (!in_word) { words++; in_word = 1; }
    }
    fclose(fp);
    printf("Total number of words: %d\n", words);
    printf("Total number of lines: %d\n", lines);
    printf("Total number of characters: %d\n", characters);
    return 0;
}

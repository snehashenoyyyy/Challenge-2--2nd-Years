#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *f = fopen("C:\\Users\\B SNEHA SHENOY\\round2\\Challenge-2--2nd-Years\\inputs\\input2.txt", "r");
    if (!f) {
        printf("Could not open file!\n");
        return 1;
    }

    char input[500];
    fscanf(f, "%s", input);
    fclose(f);

    int len = strlen(input);

    char reversed[500];
    for (int i = 0; i < len; i++) {
        reversed[i] = input[len - 1 - i];
    }
    reversed[len] = '\0';

    char removed[500];
    int idx = 0;
    for (int i = 0; i < len; i++) {
        if ((i + 1) % 3 != 0) {
            removed[idx++] = reversed[i];
        }
    }
    removed[idx] = '\0';

    int vowelCount = 0;

    for (int i = 0; i < idx; i++) {
        char shifted = removed[i] + 2;
        char lower = tolower(shifted);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
            vowelCount++;
        }
    }

    printf("Clue 2 = %d\n", vowelCount);

    return 0;
}
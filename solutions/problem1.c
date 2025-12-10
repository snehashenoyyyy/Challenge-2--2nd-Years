#include <stdio.h>
#include <string.h>

void trim(char *s){
    size_t n = strlen(s);
    while (n>0 && (s[n-1]=='\n' || s[n-1]=='\r')) { s[n-1]=0; --n; }
}

int main(void){
    // Attempt to open files in the current folder
    const char *gname = "grid.txt";
    const char *dname = "directions.txt";

    printf("Trying to open files from current folder:\n");
    printf(" - %s\n - %s\n\n", gname, dname);

    FILE *fg = fopen(gname, "r");
    if (!fg) { perror("ERROR opening grid.txt"); return 1; }
    FILE *fd = fopen(dname, "r");
    if (!fd) { perror("ERROR opening directions.txt"); fclose(fg); return 1; }

    // Print first line of each so we confirm they're the correct files
    char line[512];
    if (fgets(line, sizeof(line), fg)) {
        trim(line);
        printf("grid.txt first line: %s\n", line);
    } else {
        printf("grid.txt appears empty or unreadable\n");
    }
    if (fgets(line, sizeof(line), fd)) {
        trim(line);
        printf("directions.txt first token/line: %s\n", line);
    } else {
        printf("directions.txt appears empty or unreadable\n");
    }
    rewind(fg); rewind(fd);

    // Now the normal program logic (simple and safe)
    char grid[100][200];
    char dirs[100];
    int rows = 0;

    while (rows < 100 && fgets(grid[rows], sizeof(grid[rows]), fg)) {
        trim(grid[rows]);
        if (grid[rows][0] != '\0') rows++;
    }

    // read directions (whitespace separated)
    int dcount = 0;
    char token[64];
    while (dcount < rows && fscanf(fd, " %63s", token) == 1) {
        dirs[dcount++] = token[0];
    }

    if (dcount < rows) {
        printf("\nERROR: directions found %d tokens but need %d rows\n", dcount, rows);
        fclose(fg); fclose(fd);
        return 1;
    }

    // rotate rows
    for (int i = 0; i < rows; ++i) {
        int len = strlen(grid[i]);
        if (len == 0) continue;
        char tmp[200];
        if (dirs[i] == 'R' || dirs[i] == 'r') {
            tmp[0] = grid[i][len-1];
            memcpy(tmp+1, grid[i], len-1);
        } else { // L or default
            memcpy(tmp, grid[i]+1, len-1);
            tmp[len-1] = grid[i][0];
        }
        tmp[len] = '\0';
        strncpy(grid[i], tmp, sizeof(grid[i])-1);
    }

    // print transformed grid
    printf("\nTransformed grid:\n");
    for (int i = 0; i < rows; ++i) printf("%s\n", grid[i]);

    int center = rows / 2;
    int sum = 0;
    for (size_t k = 0; k < strlen(grid[center]); ++k) sum += (unsigned char)grid[center][k];

    printf("\nCentral row (index %d): %s\n", center, grid[center]);
    printf("Clue 1 (ASCII sum): %d\n", sum);

    fclose(fg);
    fclose(fd);
    return 0;
}
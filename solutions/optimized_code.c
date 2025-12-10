#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    FILE *f = fopen("C:\\Users\\B SNEHA SHENOY\\round2\\Challenge-2--2nd-Years\\inputs\\states.txt", "r");
    if (!f) {
        printf("Could not open states.txt\n");
        return 1;
    }

    int x;
    int countFinal = 0;

    while (fscanf(f, "%d", &x) == 1) {
        if (isPrime(x)) {
            countFinal++;
        } 
        else if (x % 2 == 0) {  
            countFinal++;
        }
        
    }

    fclose(f);

    printf("%d\n", countFinal);
    return 0;
}
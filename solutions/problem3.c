#include <stdio.h>
#include <stdlib.h>

int is_prime(int n){
    if(n <= 1) return 0;
    if(n <= 3) return 1;
    if(n % 2 == 0) return 0;
    for(int i = 3; i*i <= n; i += 2)
        if(n % i == 0) return 0;
    return 1;
}

int main(void){
    FILE *f = fopen("C:\\Users\\B SNEHA SHENOY\\round2\\Challenge-2--2nd-Years\\inputs\\states.txt", "r");
    if(!f){
        printf("Error: cannot open inputs/states.txt\n");
        return 1;
    }
    int val;
    int clue3 = 0;
    while(fscanf(f, "%d", &val) == 1){
        int state = 0;
        while(state < 3){
            if(is_prime(val)){
                state = 3;
                break;
            } else if(val % 2 == 0){
                state = state + 1;
            } else {
                break;
            }
        }
        if(state == 3) clue3++;
    }
    fclose(f);
    printf("Clue 3: %d\n", clue3);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>


int integerBreak(int n){
    int fn[10] = {0, 1, 1, 2, 4, 5, 9, 12, 18, 27};
    int total = 1;
    while (n >= 10) {
        total *= 3;
        n -= 3;
    }
    total *= fn[n];
    return total;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return -1;
    }
    printf("%s:%d\n", argv[1], integerBreak(atoi(argv[1])));
    return 0;
}

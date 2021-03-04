#include <stdio.h>
#include <stdlib.h>

int count_5(int n) {
    int count = 0;
    while (n > 4 && 0 == (n % 5)) {
        count += 1;
        n /= 5;
    }
    return count;
}

int trailingZeroes(int n){
    int i, m;
    int count = 0;
    for (i = 5; i <= n; i += 5) {
        for (m = i; m > 4 && 0 == (m % 5); m /= 5) {
            count++;
        }
    }
    return count;
}

int
main(int argc, char *argv[]) {
    int n = 0;
    if (argc < 2) {
        printf("usage:%s  n\n", argv[0]);
        return -1;
    }
    n = atoi(argv[1]);
    printf("%d\n", trailingZeroes(n));
    return 0;
}

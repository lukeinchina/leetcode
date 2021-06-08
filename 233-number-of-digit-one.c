#include <stdio.h>
#include <stdlib.h>

int calc_base(int n, int *order, int *highest) {
    int base = 1;
    *order  = 0;
    for (; n > 0; n /= 10) {
        *order += 1;
        base   *= 10;
        *highest = n;
    }
    base   /= 10;
    *order -= 1;
    return base;
}

int countDigitOne(int n){
    static int dp[10] = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000};
    int total = 0;
    int base, order, h;

    while (n > 0) {
        if (n < 10) {
            total += 1;
            return total;
        }
        base = calc_base(n, &order, &h);

        printf("base:%d, order:%d, highest digit:%d\n", base, order, h);

        if (h > 1) {
            total += base + h * dp[order];
        } else {
            total += (n - base * h + 1) + dp[order];
        }

        /* for next loop */
        n -= h * base;
    }
    return total;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage: %s n\n", argv[0]);
        return -1;
    }
    printf("solution:%d\n", countDigitOne(atoi(argv[1])));
    return 0;
}

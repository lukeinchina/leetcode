#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

int divide(int dividend, int divisor){
    int i = 0;
    long long m, n, val;
    long long  flag = 1;
    if (dividend > 0 && divisor > 0) {
        m = dividend;
        n = divisor;
    } else if (dividend > 0 && divisor < 0) {
        flag = -1;
        m = dividend;
        n = -1L * divisor;
    } else if (dividend < 0 && divisor > 0) {
        flag = -1;
        m = -1L * dividend;
        n = divisor;
    } else if (dividend < 0 && divisor < 0) {
        m = -1L * dividend;
        n = -1L * divisor;
    } else {
        return 0;
    }

    for (i = 0; m >= n; n <<= 1) {
        i++;
    }
    val = 0;
    for (; i > 0; i--) {
        n >>= 1;
        val <<= 1;
        if (m >= n) {
            m -= n;
            val += 1;
        }
    }
    val *= flag;

    return val > (long long)INT_MAX ? INT_MAX : val;
}

int
main(void) {
    /*
    printf("%d\n", divide(1, 1));
    printf("%d\n", divide(-5, 3));
    printf("%d\n", divide(15, 15));
    printf("%d\n", divide(-5, -3));
    printf("%d\n", divide(3, 5));
    printf("%d\n", divide(5000, 1)); */
    printf("%d\n", divide(-2147483648, -1));
    return 0;
}

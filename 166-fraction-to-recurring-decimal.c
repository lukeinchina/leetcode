#include <stdio.h>
#include <stdlib.h>

/* 商（quotient）和余数（residue） */

/* 返回值表示是商, n > 0 && m > 0 */
int divide(long n, long m) {
    int quot = 0;
    return exact;
}

char * fractionToDecimal(int numerator, int denominator){
    long n = numerator;
    long m = demominator;
    int flag = 1;
    int quot = 0;

    if (0L == n) {
        return "0";
    }

    if ((n > 0 && m < 0) || (n < 0 && m > 0)) {
        flag = -1;
    }
    if (n < 0) {
        n *= -1;
    }
    if (m < 0) {
        m *= -1;
    }

    if (n > m) {
        a = divide(n, m);
    }

    n = n % m;
    if (n) {
        divide_fraction(n, m);
    }
}

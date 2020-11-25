#include <stdio.h>
#include <stdlib.h>

/* 这两个算法居然运行性能差不多
double my_pow(double x, long n) {
    long i = 0;
    double x2,x4,x8,x16,x64;
    double val = 1.0;
    if (n >= 8) {
        x2 = x * x;
        x4 = x2 * x2;
        x8 = x4 * x4;
        x16 = x8 * x8;
    }
    if (n >= 64) {
        x64 = x16 * x16 * x16 * x16;
    }
    for (; i+64 <= n; i += 64) {
        val *= x64;
    }
    for (; i+16 <= n; i += 16) {
        val *= x16;
    }
    for (; i+8 <= n; i += 8) {
        val *= x8;
    }
    for (; i < n; i++) {
        val *= x;
    }
    return val;
}
*/

/* n is positive */
double my_pow(double x, long n) {
    double total = 1.0;
    double curr  = x;
    long long mask = 1L;
    /* 因为是整数，不会大于32位 */
    do {
        if(mask & n) {
            total *= curr;
        }
        mask <<= 1;
        curr *= curr; 
    }while (mask <= n);
    return total;
}

double myPow(double x, int n){
    if (n == 0) {
        return 1;
    } 
    long l = n;
    return n < 0 ? 1.0/my_pow(x, -1 * l) : my_pow(x, l);
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage:%s x n\n", argv[0]);
        return -1;
    }
    printf("%f\n", myPow(atof(argv[1]), atoi(argv[2])));
    return 0;
}

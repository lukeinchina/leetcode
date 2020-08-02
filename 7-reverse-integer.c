#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int reverse(int x){
    long val  = 0;
    int flag = 1;
    if (x == INT_MIN) {
        return 0;
    }
    if (x < 0) {
        flag = -1;
        x   *= -1;
    }
    /* trim 0 */
    while ((0 != x) && 0 == (x % 10)) {
        x /= 10;
    }
    while (x > 0) {
        val = val * 10 + x % 10;
        x   /= 10;
        if (val > INT_MAX) {
            return 0;
        }
    }
    return val * flag;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s int\n", argv[0]);
        return -1;
    }

    printf("%s reverse %d\n", argv[1], reverse(atoi(argv[1])));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int nthUglyNumber(int n){
    int i, x, y, z, val = 1;
    x = y = z = 0;

    for (i = 0; i < n; i++) {
        if (0 == x && 0 == y && 0 == z) {
            x += 1;
        } else if (z > 0 && y > 0) {
            x += 4;
            y--;
            z--;
        } else if (z > 0 && x > 0) {
            z--;
            y++;
            x++;
        } else if (y > 0 && x > 0) {
            x += 2;
            y--;
        } else if (z > 0) {
            z--;
            x++;
            y++;
        } else if (y > 0) {
            x += 2;
            y--;
        } else if (x > 0) {
            ;
        }
    }
    for (i = 0; i < x; i++) {
        val *= 2;
    }
    for (i = 0; i < y; i++) {
        val *= 3;
    }
    for (i = 0; i < z; i++) {
        val *= 5;
    }
    return val;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s \n", argv[0]);
        return -1;
    }
    printf("%d\n", nthUglyNumber(atoi(argv[1])));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x){
    double v, vn;
    v = 1.0;
    vn = 2.0;
    while (vn - v > 0.000001 || vn-v < -0.000001) {
        v = vn;
        vn = 0.5 * (v + x/v);
    }
    return (int)v;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return 0;
    }
    printf("%d\n", mySqrt(atoi(argv[1])));
    return 0;
}

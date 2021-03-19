#include <stdio.h>
#include <stdlib.h>


int rangeBitwiseAnd(int left, int right){
    long n = left;
    long l = left;
    long r = right;

    if ((right >> 1) >= left) {
        return 0;
    }
    while (n > 0L &&  l <= r) {
        n = n & l & r;
        l++;
        r--;
    }
    return (int)n;
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage:%s a b \n", argv[0]);
        return -1;
    }
    printf("%d\n", rangeBitwiseAnd(atoi(argv[1]), atoi(argv[2])));
    return 0;
}

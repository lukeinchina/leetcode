#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        count++;
        n &= (n-1);
    }
    return count;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return -1;
    }
    printf("%d\n", hammingWeight(atoi(argv[1])));
    return 0;
}

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t reverseBits(uint32_t n) {
    int i;
    uint32_t high, low;
    uint32_t rev = 0U;

    printf("%u\n", n);

    for (i = 0; i < 16; i++) {
        high = (0X80000000U >> i) & n;
        low  = (1U << i) & n;
        rev |= (low << (31-2*i)) | (high >> (31-2*i));
    }
    return rev;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return -1;
    }
    printf("%u\n", reverseBits(atoi(argv[1])));
    return 0;
}

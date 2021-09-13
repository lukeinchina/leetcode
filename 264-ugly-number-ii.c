#include <stdio.h>
#include <stdlib.h>

int nthUglyNumber(int n){
    int first[10] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12};
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

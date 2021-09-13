#include <stdio.h>
#include <stdlib.h>

bool isUgly(int n){
    while (n % 2 == 0) {
        n /= 2;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    while (n % 5 == 0) {
        n /= 5;
    }
    return n == 1;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s \n", argv[0]);
        return -1;
    }
    printf("%d\n", isUgly(atoi(argv[1])));
    return 0;
}

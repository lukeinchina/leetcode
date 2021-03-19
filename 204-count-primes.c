#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countPrimes(int n){
    int i, j, m;
    int count;

    if (n < 2) {
        return 0;
    }
    count = (n < 4 ? n-2 : 2);

    for (i = 5; i < n; i += 2) {
        m = sqrt(i);
        for (j = 2; j <= m; j++) {
            if (i % j == 0) {
                break;
            }
        }
        count += (j > m);
    }
    return count;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return -1;
    }
    printf("%d\n", countPrimes(atoi(argv[1])));
    return 0;
}

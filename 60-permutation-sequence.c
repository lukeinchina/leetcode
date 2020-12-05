#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_kth_perm(char *p, int n, int k) {
    int i, j, unit, total = 1;
    char tmp;
    if (1 == n) {
        return;
    }
    for (i = 0; i < n; i++) {
        total *= (i+1);
    }
    unit = total / n;
    for (i = 0; i < n; i++) {
        if (unit * (i+1) >= k) {
            break;
        }
    }
    tmp = p[i];
    for (j = i; j > 0; j--) {
        p[j] = p[j-1];
    }
    p[0] = tmp;
    get_kth_perm(p+1, n-1, k- unit * i);
}

char * getPermutation(int n, int k){
    int   i = 0;
    char *p = (char *)malloc(n+1);
    for (i = 0; i < n; i++) {
        p[i] = i+1 + '0';
    }
    p[n] = '\0';
    get_kth_perm(p, n, k);
    return p;
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage:%s n k\n", argv[0]);
        return 0;
    }

    printf("%s\n", getPermutation(atoi(argv[1]), atoi(argv[2])));

    return 0;
}

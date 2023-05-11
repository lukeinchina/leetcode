#include <stdio.h>
#include <stdlib.h>

int nthUglyNumber(int n){
    int *dp = (int *)malloc(sizeof(int) * n );
    int i, p2,p3,p5, nth, n2, n3, n5;
    p2 = p3 = p5 = 0;
    dp[0] = 1;
    for (i = 1; i < n; i++) {
        n2 = dp[p2] * 2;
        n3 = dp[p3] * 3;
        n5 = dp[p5] * 5;
        nth = n2 < n3 ? n2 : n3;
        dp[i] = nth = n5 < nth ? n5 : nth;
        if (nth == n2) {
            p2++;
        }
        if (nth == n3) {
            p3++;
        }
        if (nth == n5) {
            p5++;
        }
    }
    free(dp);
    return nth;
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

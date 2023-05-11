#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int nthSuperUglyNumber(int n, int* primes, int primesSize){
    int min, i, j, ugly;
    int *dp = (int *)malloc(sizeof(int) * n);
    int *nums = (int *)malloc(sizeof(int) * primesSize);
    int *ps = (int *)malloc(sizeof(int) * primesSize);
    ugly = dp[0] = 1;

    for (i = 0; i < primesSize; i++) {
        ps[i] = 0;
    }
    for (i = 1; i < n; i++) {
        min = INT_MAX;
        for (j = 0; j < primesSize; j++) {
            nums[j] = dp[ps[j]] * primes[j];
            if (nums[j] < min) {
                min = nums[j];
            }
        }
        ugly = dp[i] = min;
        for (j = 0; j < primesSize; j++) {
            if (min == dp[ps[j]] * primes[j]) {
                ps[j] += 1;
            }
        }
    }
    free(dp);
    free(ps);
    free(nums);
    return ugly;
}

int
main(int argc, char *argv[]) {
    int primes[] = {2, 3, 5};
    int n = 0;
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return 1;
    }
    n = nthSuperUglyNumber(atoi(argv[1]), primes, sizeof(primes) / sizeof(primes[0]));
    printf("%d\n", n);
    return 0;
}

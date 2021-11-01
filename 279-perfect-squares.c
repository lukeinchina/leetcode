#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_array(const int nums[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1 == size ? '\n' : '\t');
    }
}

void find_cand(int n, int *max, int count, int stack[]) {
    int i, tmp, begin, left = n;

    i = begin = (int)sqrt(n);
    while (i > 0) {
        if (count >= *max) {
            break;
        }
        tmp = i * i;

        if (left < tmp) {
            i--;
            continue;
        } else if (left == tmp) {
            stack[count++] = i;
            *max = (count > *max) ?  *max : count;
            print_array(stack, count);
            break;
        }
        /* 放入 i^2 */
        left -= tmp;
        stack[count++] = i;
//        find_cand(left, max, count, stack);
    }
}

int numSquares(int n){
    int f[] = {0, 1, 2, 3, 1, 2, 3, 4, 2, 1};
    int i, j, min, t;
    int *dp = NULL; 
    if (n <= 9) {
        return f[n];
    }
    dp = (int *)calloc(n+1, sizeof(int));
    for (i = 0; i <= 9; i++) {
        dp[i] = f[i];
    }
    for (i = 10; i <= n; i++) {
        t = sqrt(i);
        if (t * t == i) {
            dp[i] = 1;
            continue;
        }

        min = i;
        for (j = 1; j <= i/2; j++) {
            if (dp[j] + dp[i-j] < min) {
                min = dp[j] + dp[i-j];
            }
        }
        dp[i] = min;
    }
    min = dp[n];
    free(dp);
    return min;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return -1;
    }
    printf("solution:%d\n", numSquares(atoi(argv[1])));
    return 0;
}

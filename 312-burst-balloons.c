#include <stdio.h>
#include <stdlib.h>

int **create_m(int row, int col) {
    int i;
    int **m = (int **)malloc(sizeof(int *) * row);
    for (i = 0; i < row; i++) {
        m[i] = (int *)malloc(sizeof(int) * col);
    }
    return m;
}

int **free_m(int **m, int row, int col) {
    int i;
    for (i = 0; i < row; i++) {
        free(m[i]);
    }
    free(m);
    return NULL;
}

int maxCoins(int* nums, int numsSize){
    int i, j, k, max, tmp, n = numsSize;
    int **dp = create_m(numsSize, numsSize);

    for (i = 0; i < n; i++) {
        dp[i][i] = nums[i];
    }

    for (k = 1; k < n; k++) {
        for (i = 0; i+k < n; i++) {
            /* dp */
            max = 0;
            for (j = i; j <= i+k; j++) {
                tmp = dp[i][j] + nums[j]
            }
            dp[i][i+k] = max;
        }
    n = dp[0][numsSize-1];
    free_m(dp, numsSize, numsSize);
    return n;
}

int
main(int argc, char *argv[]) {
    int nums[] = {3,1,5,8};
    int max = maxCoins(nums, sizeof(nums) / sizeof(nums[0]));
    printf("max = %d\n", max);
    return 0;
}

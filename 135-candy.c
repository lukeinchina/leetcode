#include <stdio.h>
#include <stdlib.h>

int candy(int* ratings, int ratingsSize){
    int i, j, *dp;
    long total = 0;
    if (ratingsSize < 1) {
        return 0;
    }
    dp = (int *)malloc(sizeof(int) * ratingsSize);
    dp[0] = 1;
    for (i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i-1]) {
            dp[i] = dp[i-1] + 1;
            continue;
        }
        dp[i] = 1;
        for (j = i-1; j >= 0 && ratings[j] >= ratings[j+1]; j--) {
            if (ratings[j] > ratings[j+1] && dp[j] <= dp[j+1]) {
                dp[j] += 1;
            } else {
                break;
            }
        }
    }
    /* debug */
    for (i = 0; i < ratingsSize; i++) {
        printf("%d%c", dp[i], i+1 == ratingsSize ? '\n' : '\t');
        total += dp[i];
    }
    free(dp);
    return total;
}


int candy2(int* ratings, int ratingsSize){
    int i, *nums;
    long total = 0;
    if (ratingsSize < 1) {
        return 0;
    }

    nums = (int *)malloc(sizeof(int) * ratingsSize);
    for (i = 0; i < ratingsSize; i++) {
        nums[i] = 1;
    }
    for (i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i-1]) {
            nums[i] = nums[i-1] + 1;
        }
    }
    total = nums[ratingsSize-1];
    for (i = ratingsSize-2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1]) {
            nums[i] = (nums[i+1] + 1 > nums[i] ? nums[i+1] + 1 : nums[i]);
        }
        total += nums[i];
    }
    /* debug */
    for (i = 0; i < ratingsSize; i++) {
        printf("%d%c", nums[i], i+1 == ratingsSize ? '\n' : '\t');
    }
    printf("%d\n", total);
    free(nums);
    return total;
}

int
main(void) {
    int nums[] = {1,3,2,2,1};
    int n = candy(nums, sizeof(nums) / sizeof(nums[0]));
    printf("%d\n", n);
    candy2(nums, sizeof(nums) / sizeof(nums[0]));
    return 0;
}

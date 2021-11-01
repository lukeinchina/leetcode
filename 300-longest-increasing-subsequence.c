#include <stdio.h>
#include <stdlib.h>

int lengthOfLIS(int* nums, int numsSize){
    int i, j, len, max = 0;
    int *dp = (int *)calloc(numsSize, sizeof(int));
    for (i = 0; i < numsSize; i++) {
        max = 1;
        for (j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                max = (dp[j] + 1 > max ? dp[j] + 1 : max);
            }
        }
        dp[i] = max;
        len = (len > max ? len : max);
    }
    free(dp);
    return len;
}

int
main(void) {
    int nums[] = {1,3,6,7,9,4,10,5,6};
    int array[] = {10,9,2,5,3,7,101,18};
    int spec[] = {9, 8, 7, 7, 7, 7};
    printf("%d\n", lengthOfLIS(nums, sizeof(nums) / sizeof(nums[0])));
    printf("%d\n", lengthOfLIS(array, sizeof(array) / sizeof(array[0])));
    printf("%d\n", lengthOfLIS(spec, sizeof(spec) / sizeof(spec[0])));
    return 0;
}

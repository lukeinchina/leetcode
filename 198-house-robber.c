#include <stdio.h>

int rob(int* nums, int numsSize){
    int i, prev, pprev, curr;
    prev = pprev = curr = 0;
    if (numsSize < 1) {
        return 0;
    } 
    if (numsSize < 2) {
        return nums[0];
    }
    if (numsSize < 3) {
        return nums[0] > nums[1] ? nums[0] : nums[1];
    }

    pprev = nums[0];
    prev  = nums[0] > nums[1] ? nums[0] : nums[1];
    for (i = 2; i < numsSize; i++) {
        curr  = (pprev + nums[i] > prev ? pprev + nums[i] : prev);
        pprev = prev;
        prev  = curr;
    }
    return prev;
}

int
main(void) {
//int nums[] = {2,7,9,3,1};
    int nums[] = {1,2,3,1};
    printf("%d\n", rob(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}

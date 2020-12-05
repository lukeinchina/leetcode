#include <stdio.h>

int maxSubArray(int* nums, int numsSize){
    int acc, max, i;
    int begin, end;
    acc = max = 0;
    for (i = 0; i < numsSize; i++) {
        acc += nums[i];
        if (acc < nums[i]) {
            acc = nums[i];
            begin = i;
        } else if (acc > max) {
            max = acc;
            end = i;
        }
    }
    printf("[%d,%d]\n", begin, end);
    return max;
}

int
main(void) {
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d\n", maxSubArray(nums, sizeof(nums)/sizeof(nums[0])));
}

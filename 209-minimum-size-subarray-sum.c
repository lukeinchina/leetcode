#include <stdio.h>
#include <limits.h>

int minSubArrayLen(int target, int* nums, int numsSize){
    int i, j;
    int sum, min;
    i = j = 0;
    sum = 0;
    min = INT_MAX;
    while (j < numsSize) {
        sum += nums[j++];
        while (sum >= target) {
            if (sum >= target && j - i < min) {
                min = j - i;
            }
            sum -= nums[i++];
        } 
    }
    return (min < INT_MAX ? min : 0);
}

int
main(void) {
    int nums[] = {1, 1, 1, 1, 1,1,1 ,1, 1};
    int n =  minSubArrayLen(11, nums, sizeof(nums) / sizeof(nums[0]));
    printf("%d\n", n);
    return 0;
}

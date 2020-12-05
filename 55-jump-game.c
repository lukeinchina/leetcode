#include <stdio.h>

bool canJump(int* nums, int numsSize){
    int max = nums[0];
    int jump_index = max;
    int last_index = numsSize-1;
    int i = 1;
    while (jump_index < last_index) {
        for (; i <= jump_index && i < last_index; i++) {
            if (nums[i]+i > max) {
                max = nums[i] + i;
            }
        }
        if (max == jump_index) {
            return false;
        }
        /* next */
        jump_index = max;
    }
    return max >= last_index;
}

int
main(void) {
    /* 3,2,1,0,4 */
    // int nums[] = {1,2,3};
    int nums[] = {2,3,1,1,4};
    printf("%d\n", canJump(nums, sizeof(nums)/sizeof(nums[0])));
    return 0;
}

#include <stdio.h>

void moveZeroes(int* nums, int numsSize){
    int i, idx = 0;
    for (i = 0;i < numsSize; i++) {
        if (0 != nums[i]) {
            nums[idx++] = nums[i];
        }
    }
    while (idx < numsSize) {
        nums[idx++] = 0;
    }
}

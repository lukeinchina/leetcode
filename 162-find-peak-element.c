#include <stdio.h>

int findPeakElement(int* nums, int numsSize){
    int i, left_inc, right_desc;
    for (i = 0; i < numsSize; i++) {
        left_inc = (i == 0 || nums[i-1] < nums[i]);
        right_desc = (i+1 == numsSize || nums[i] > nums[i+1]);
        if (left_inc && right_desc) {
            return i;
        }
    }
    return 0;
}

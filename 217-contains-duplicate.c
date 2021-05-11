#include <stdio.h>
#include <stdlib.h>

int compare(const void *left, const void *right) {
    return *(int *)left - *(int *)right;
}

bool containsDuplicate(int* nums, int numsSize){
    int i;
    qsort(nums, numsSize, sizeof(int), compare);
    for (i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i-1]) {
            return true;
        }
    }
    return false;
}

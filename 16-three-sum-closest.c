#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void *left, const void *right) {
    return *(const int *)left - *(const int *)right;
}

int threeSum(int* nums, int numsSize, int target) {
    int i, j, k, sum, gap, tmp, near;
    gap = nums[0] + nums[1] + nums[2] - target;
    if (gap < 0) {
        gap = -gap;
    }
    near = nums[0] + nums[1] + nums[2];
    qsort(nums, numsSize, sizeof(int), cmp_int);
    for (i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    for (i = 0; i < numsSize; i++) {
        j   = i + 1;
        k   = numsSize - 1;
        sum = target - nums[i];
        while (j < k) {
            tmp = nums[i] + nums[j] + nums[k] - target; 
            tmp = tmp > 0 ? tmp : - tmp;
            if (tmp < gap) {
                gap = tmp;
                near = nums[i] + nums[j] + nums[k];
            }

            if (nums[j] + nums[k] < sum) {
                j++;
            }else if (nums[j] + nums[k] > sum) {
                k--;
            }else {
                return target;
            }
        }
    }
    return near;
}

int main(int argc, char *argv[]) {
    // int nums[] = {-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
    int nums[] = {-2,-1,2,-4,-1,-1,-1,-5,-4,3,-2,0};
    threeSum(nums, 12, -10);
    return 0;
}

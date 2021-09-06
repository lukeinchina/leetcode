#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int get_max(const int *nums, int size, int *index) {
    int i, max, idx;
    max = INT_MIN;
    for (i = 0; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
            idx = i;
        }
    }
    *index = idx;
    return max;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int idx, max_i, max, size, tidx, *dst;
    size = numsSize + 1 - k;
    dst  = (int *)malloc(sizeof(nums[0]) * size);
    max  = get_max(nums, k, &max_i);
    dst[0] = max;
    for (idx = 1; idx < size; idx++) {
        if (nums[idx+k-1] > max) {
            max   = nums[idx+k-1];
            max_i = idx+k-1;
        }
        /* 最大值被移出窗口，需要重新计算 */
        if (max_i < idx) {
            max = get_max(nums+idx, k, &tidx);
            max_i = tidx + idx;
        }
        dst[idx] = max;
    }
    *returnSize = size;
    return dst;
}

int 
main(int argc, char *argv[]) {
    int nums[] = {4, 3, -1, -3, 5, 3, 6, 7};
    int i, size;
    int *array = maxSlidingWindow(nums, 2, 2, &size);
    printf("count:%d\n", size);
    for (i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
    free(array);
    return 0;
}

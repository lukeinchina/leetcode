#include <stdio.h>
#include <stdlib.h>

void include_
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int i,j,total = 1;
    int elem[32];
    int size = 0;
    int nzero = 0;
    int *dst = (int *)calloc(numsSize, sizeof(int));
    *returnSize = numsSize;

    /* 多0 */
    for (i = 0; i < numsSize; i++) {
        if (0 == nums[i]) {
            nzero++;
        }
    }
    if (1 == nzero) {
        total = 1;
        for (i = 0; i < numsSize; i++) {
            if (0 == nums[i]) {
                j = i;
            } else {
                total *= nums[i];
            }
        }
        dst[j] = total;
        return dst;
    }
    if (nzero != 0) {
        return dst;
    }
}

#include <stdio.h>
#include <stdlib.h>


int product_except(int *nums, int size, int skip) {
    int i, flag, total = 1;
    flag = 1;
    for (i = 0; i < size; i++) {
        if (1 == flag && nums[i] == skip) {
            flag = 0;
        }else {
            total *= nums[i];
        }
    }
    return total;
}

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int i,j,total = 1;
    int size = 0;
    int elem[32];
    int n0, n1;
    int *dst = (int *)calloc(numsSize, sizeof(int));
    *returnSize = numsSize;

    n0 = n1 = 0;

    for (i = 0; i < numsSize; i++) {
        n0  +=  (0 == nums[i]);
        n1  +=  (-1 == nums[i]);
        if (nums[i] < -1 || nums[i] > 1) {
            elem[size++] = nums[i];
            total *= nums[i];
        }
    }
    if (n0 > 1) {
        return dst;
    } else if (n0 > 0) {
        total = 1;
        for (j = i = 0; i < numsSize; i++) {
            if (0 != nums[i]) {
                total *= nums[i];
            } else {
                j = i;
            }
        }
        dst[j] = total;
        return dst;
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] < -1 || nums[i] > 1) {
            dst[i] = product_except(elem, size, nums[i]);
        } else {
            dst[i] = total ;
        }
        if (n1 % 2) {
            dst[i] *= -1;
        }
        if (-1 == nums[i]) {
            dst[i] *= -1;
        }
    }
    return dst;
}

int
main(void) {
    int i, size = 0;
    int nums[] = {-1, -1,1, 2,-3,3};
    int *p =  productExceptSelf(nums, sizeof(nums) / sizeof(nums[0]), &size);
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    free(p);
    return 0;
}

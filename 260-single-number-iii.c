#include <stdio.h>
#include <stdlib.h>

int* singleNumber(int* nums, int numsSize, int* returnSize){
    int *dst = (int *)malloc(sizeof(int) * 2);
    int x,y,z,i;
    z = 0;
    for (i = 0; i < numsSize; i++) {
        z ^= nums[i];
    }
    
    for (i = 0; i < 32; i++) {
        if (z & (1LU<<i)) {
            x = (1LU << i);
        }
    }
    y = z = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] & x) {
            z ^= nums[i];
        } else {
            y ^= nums[i];
        }
    }
    *returnSize = 2;
    dst[0] = y;
    dst[1] = z;
    return dst;
}

int
main(int argc, char *argv[]) {
    int nums[] = {0, -1};
    int size = 0;
    int *dst = singleNumber(nums, sizeof(nums)/sizeof(nums[0]), &size);
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\n", dst[i]);
    }
    return 0;
}

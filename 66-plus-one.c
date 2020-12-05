#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i, flag, *nums;
    flag = 1;
    for (i = 0; i < digitsSize; i++) {
        if (9 != digits[i]) {
            flag = 0;
            break;
        }
    }
    *returnSize = digitsSize;
    if (flag) {
        *returnSize += 1;
        nums   = (int *)calloc(*returnSize, sizeof(int));
        nums[0] = 1;
        return nums;
    }
    flag = 1;
    nums = (int *)malloc(sizeof(int) * *returnSize);
    for (i = digitsSize - 1; i >= 0; i--) {
        nums[i] = (flag + digits[i]) % 10;
        flag = (flag + digits[i]) / 10;
    }
    return nums;
}

int
main(void) {
    int i, size;
    int nums[] = {1, 2, 3};
    int *p = plusOne(nums, sizeof(nums)/sizeof(nums[0]), &size);
    for (i = 0; i < size; i++) {
        printf("%d", p[i]);
    }
    return 0;
}

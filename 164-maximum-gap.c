#include <stdio.h>
#include <stdlib.h>

int cmp(const void *left, const void *right) {
    return *(int *)left - *(int *)right;
}

void print_array(const int *nums, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1==size ? '\n':' ');
    }
}

int maximumGap(int* nums, int numsSize){
    int i, gap = 0;
    if (numsSize < 2) {
        return 0;
    }
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    for (i = 1; i < numsSize; i++) {
        if (nums[i] - nums[i-1] > gap) {
            gap = nums[i] - nums[i-1];
        }
    }
    return gap;
}

int
main(void) {
    int nums[] = {6, 9, 3, 1};
    int n = maximumGap(nums, sizeof(nums) / sizeof(nums[0]));
    printf("%d\n", n);
    return 0;
}

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *nums, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1 == size ? '\n' : '\t');
    }
}

int cmp(const void *left, const void *right) {
    return *(const int *)left - *(const int *)right;
}

int longestConsecutive(int* nums, int numsSize){
    int i, longest, total;
    if (numsSize < 1) {
        return 0;
    }

    longest = total = 1;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (i = 1;  i < numsSize; i++) {
        if (nums[i-1]+1 == nums[i]) {
            total++;
        } else if (nums[i-1] == nums[i]) {
            continue;
        } else {
            total = 1;
        }

        longest = total > longest ? total : longest;
    }
    return longest;
}


int
main(void) {
    int nums[] = {100,4,200,1,3,2};
    // int nums[] = {0,3,7,2,5,8,4,6,0,1};
    int n = longestConsecutive(nums, sizeof(nums) / sizeof(nums[0]));
    print_array(nums, sizeof(nums) / sizeof(nums[0]));
    printf("%d\n", n);
}


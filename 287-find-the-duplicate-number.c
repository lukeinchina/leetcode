#include <stdio.h>

int findDuplicate(int* nums, int numsSize){
    int i, n, left, right, mid;
    left = 1;
    right = numsSize - 1;
    while (left < right) {
        n   = 0;
        mid = (left + right) / 2;
        for (i = 0; i < numsSize; i++) {
            if (nums[i] >= left && nums[i] <= mid) {
                n++;
            }
        }
        /* 不在左边 */
        if (n <= (mid - left + 1)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main(void) {
    int nums[] = {1,1};
    printf("%d\n", findDuplicate(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}

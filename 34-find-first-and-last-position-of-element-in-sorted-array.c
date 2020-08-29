#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int left, right, mid, pos;
    int *ans = (int *)malloc(sizeof(int) * 2);
    ans[0] = ans[1] = -1;
    *returnSize = 2;

    /* 第一次出现 */
    pos   = -1;
    left  = 0;
    right = numsSize - 1;
    while (left <= right) {
        mid = ((right - left) >> 1) + left;
        if (nums[mid] < target) {
            left  = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            pos   = mid;
            right = mid-1;
        }
    }
    if (-1 == pos) {
        return ans;
    }
    ans[0] = pos;
    /* 最后一次出现 */
    left = pos;
    right = numsSize - 1;
    while (left <= right) {
        mid = ((right - left) >> 1) + left;
        if (nums[mid] < target) {
            left  = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            pos  = mid;
            left = mid+1;
        }
    }
    ans[1] = pos;
    return ans;
}

int
main(void) {
    int size = 0;
    int array[] = {5,7,7,8,8, 8, 8, 8, 10,10};
    int *p = searchRange(array, 10, 0, &size);
    printf("%d %d \n", p[0], p[1]);
    return 0;
}

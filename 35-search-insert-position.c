#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int l,r,m;
    l = 0; 
    r = numsSize-1;
    while (l <= r) {
        m = (r + l) / 2;
        if (nums[m] > target) {
            r = m - 1;
        }else if (nums[m] < target) {
            l = m + 1;
        }else {
            return m;
        }
    }
    return l;
}

int
main(void) {
    int array[] = {1,3,6,7};
    int idx = searchInsert(array, 4, 0);
    printf("%d\n", idx);
    return 0;
}

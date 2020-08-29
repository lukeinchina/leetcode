#include <stdio.h>

int search(int* nums, int numsSize, int target){
    int l = 0;
    int r = numsSize-1;
    int m = 0;
    while (l < r) {
        if (r - l <= 5) {
            for (; l < r; l++) {
                if (nums[l] > nums[l+1]) {
                    m = l+1;
                    break;
                }
            }
            break;
        }
        m = (l + r) / 2;
        if (nums[l] < nums[m]) {
            l = m;
        } else {
            r = m;
        }
    }
    r = numsSize - 1;
    if (m == 0) {
        l = 0;
    }else if (target >= nums[0] && target <= nums[m-1]) {
        l = 0;
        r = m-1;
    } else if (target >= nums[m] && target <= nums[r]) {
        l = m;
    } else {
        return -1;
    }
    /* binary search */
    while (l <= r) {
        m = (l + r) / 2;
        if (target < nums[m]) {
            r = m-1;
        }else if (target > nums[m]) {
            l = m+1;
        }else {
            return m;
        }
    }
    return -1;
}

int
main(void) {
    int array[] = {4,5,6,7,0,1,2};
    int idx = search(array, 2, 4);
    printf("%d\n", idx);
    return 0;
}

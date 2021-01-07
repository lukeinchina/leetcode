#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target){
    int m,l,r;
    l = 0;
    r = numsSize - 1;
    while (l <= r) {
        m = (l + r) / 2;
        if (nums[m] == target) {
            return 1;
        } 

        if (nums[m] < nums[r]) {
            if (target >= nums[m] && target <= nums[r]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        } else if (nums[l] < nums[m]) {
            if (target >= nums[l] && target <= nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        } else {
            l++;
        }
    }
    return 0;
}

int
main(int argc, char *argv[]) {
    int nums[] = {3,1,6,0,0,1,2};
    if (argc < 2) {
        printf("usage:%s k\n", argv[0]);
        return -1;
    }
    // printf("%d\n", search(nums, sizeof(nums)/sizeof(nums[0]), atoi(argv[1])));
    printf("%d\n", search(nums, 2, atoi(argv[1])));
    return 0;
}

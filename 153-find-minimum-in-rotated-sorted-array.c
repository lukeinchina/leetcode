#include <stdio.h>

int findMin(int* nums, int numsSize){
    int left, right, mid;
    left  = 0; 
    right = numsSize -1;
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[left] <= nums[mid] && nums[mid] <= nums[right]) {
            return nums[left];
        } 

        if (left == mid){
            return nums[mid] > nums[right] ? nums[right] : nums[mid];
        } else if (nums[left] < nums[mid]) {
            left = mid+1;
        } else {
            right = mid;
        }
    }
    return nums[right];
}

int
main(void) {
    int nums[] = {4, 5, 6, 9, 1, 2};
    int min = findMin(nums, sizeof(nums) / sizeof(nums[0]));
    printf("%d\n", min);
    return 0;
}

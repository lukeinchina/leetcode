#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize){
    int i, tmp, k;
    for (i = 0; i < numsSize; i++) {
        k = nums[i];
        while (k <= numsSize && k > 0 && nums[k-1] != k){
            tmp = nums[k-1];
            nums[k-1] = k;
            k = tmp;
        }
    }
    for (i = 0; i < numsSize; i++) {
        if(nums[i] > numsSize || nums[i] <= 0 || nums[i] != i+1) {
            break;
        }
    }
    return i+1;
}

int
main(void) {
    int arr[] = {3, 4, -1,1,11,12};
    printf("%d\n", firstMissingPositive(arr, 4));
    return 0;
}

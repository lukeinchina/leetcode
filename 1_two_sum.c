#include <stdio.h>
#include <stdlib.h>

int* 
twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int *array = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (i = 0; i < numsSize; i++) {
        for (j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                array[0] = nums[i];
                array[1] = nums[j];
                goto END;
            }
        }
    }

END:
    return array;
}

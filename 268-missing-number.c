#include <stdio.h>

int missingNumber(int* nums, int numsSize){
    int i;
    long long total = 0;
    long long multi = 0 + numsSize;
    multi *= numsSize + 1;
    multi >>= 1;
    for (i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    return (multi - total);
}

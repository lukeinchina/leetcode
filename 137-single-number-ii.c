#include <stdio.h>

int singleNumber(int* nums, int numsSize){
    int i, idx, val = 0;
    int counts[32] = {0};
    int  bits[32] = {\
    0X80000000, 0X40000000, 0X20000000, 0X10000000, \
    0X08000000, 0X04000000, 0X02000000, 0X01000000, \
    0X00800000, 0X00400000, 0X00200000, 0X00100000, \
    0X00080000, 0X00040000, 0X00020000, 0X00010000, \
    0X00008000, 0X00004000, 0X00002000, 0X00001000, \
    0X00000800, 0X00000400, 0X00000200, 0X00000100, \
    0X00000080, 0X00000040, 0X00000020, 0X00000010, \
    0X00000008, 0X00000004, 0X00000002, 0X00000001, \
    };
    for (idx = 0; idx < 32; idx++) {
        for (i = 0; i < numsSize; i++) {
            counts[idx] += ((bits[idx] & nums[i]) != 0);
        }
    }
    for (idx = 0; idx < 32; idx++) {
        counts[idx] %= 3;
    }
    for (idx = 0; idx < 32; idx++) {
        if (counts[idx]) {
            val |= bits[idx];
        }
    }

    return val;
}

int
main(void) {
    int nums[] = {2,2,2, -4};
    printf("solution:%d\n", singleNumber(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void rotate(int* nums, int numsSize, int k){
    int i, t, v, begin, idx;

    k %= numsSize;
    if (0 == k) {
        return ;
    }
    idx = begin = 0;
    v = nums[idx];
    for (i = 0; i < numsSize; i++) {
        t = nums[(idx+k) % numsSize]; 
        nums[(idx+k) % numsSize] = v;
        idx = (idx + k) % numsSize;
        if (idx == begin) {
            idx = ++begin;
            v = nums[idx];
        }else {
            v = t;
        }
    }
}

void print_array(const int *nums, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1 == size ? '\n' : '\t');
    }
}

int
main(int argc, char *argv[]) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8};
    if (argc < 2) {
        printf("usage:%s k\n", argv[0]);
        return -1;
    }
    rotate(nums, sizeof(nums) / sizeof(nums[0]), atoi(argv[1]));
    print_array(nums, sizeof(nums) / sizeof(nums[0]));
    return 0;
}

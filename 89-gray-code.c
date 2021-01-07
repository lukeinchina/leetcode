#include <stdio.h>
#include <stdlib.h>

int* grayCode(int n, int* returnSize){
    int i, j, size, bit_mask, *nums;
    *returnSize = (1 << n);
    nums = (int *)calloc(*returnSize, sizeof(int));
    if (n < 1)  {
        return nums;
    }
    nums[1] = 1;
    for (i = 2; i <= n; i++) {
        size     = (1 << (i-1));
        bit_mask = (1 << (i-1));
        for (j = 0; j < size; j++) {
            nums[size+j] = bit_mask | nums[size-j-1];
        }
    }
    printf("%d\n", *returnSize);
    return nums;
}

void print_array(const int *nums, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1 == size ? '\n' : '\t');
    }
}

int
main(int argc, char *argv[]) {
    int size, *nums;
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return -1;
    }
    nums = grayCode(atoi(argv[1]), &size);
    if (size > 0) {
        print_array(nums, size);
    }
    return 0;
}

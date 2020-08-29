#include <stdio.h>
#include <stdlib.h>
#include "common/array.h"

int cmp_int(const void *l, const void *r) {
    return (*(int *)l - *(int *)r);
}

void cambinate_sum(int *nums, int size, int idx, int target, 
        int sum, int *stack, int top, struct ArrayHead *dst) {
    if (sum == target) {
        array_append_without_same(dst, stack, top);
        return ;
    }
    if (sum > target || idx >= size) {
        return ;
    }
    if (nums[idx] <= target)  {
        stack[top] = nums[idx];
        cambinate_sum(nums, size, idx+1, target, sum+nums[idx], stack, top+1, dst); 
    }
    cambinate_sum(nums, size, idx+1, target, sum, stack, top, dst); 
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int *stack = (int *)malloc(sizeof(int) * candidatesSize);
    struct ArrayHead dst = {NULL, NULL, 0, 0};

    qsort(candidates, candidatesSize, sizeof(int), cmp_int);
    cambinate_sum(candidates, candidatesSize, 0, target, 0, stack, 0, &dst);
    free(stack);

    *returnSize        = dst.size;
    *returnColumnSizes = dst.cols;

    array_print(&dst);
    return dst.array;
}

int
main(int argc, char *argv[]) {
    int target = 0;
    int array[] = {10,1,2,7,6,1,5};
    int *colsizes;
    int retsize;
    int **pp;
    if (argc < 2) {
        printf("usage:%s target\n", argv[0]);
        return -1;
    }
    target = atoi(argv[1]);
    pp = combinationSum2(array, sizeof(array)/sizeof(array[0]), target, &retsize, &colsizes);
    printf("result count: %d\n", retsize);
    return 0;
}

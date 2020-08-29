#include <stdio.h>
#include <stdlib.h>
#include "common/array.h"

int cmp_int(const void *l, const void *r) {
    return (*(int *)l - *(int *)r);
}

void cambinate_sum(int *nums, int size, int target, 
        int begin, int *stack, int top, struct ArrayHead *dst) {
    int i = 0;
    if (0 == target) {
        array_append(dst, stack, top);
        return ;
    }
    if (target < 0) {
        return ;
    }
    for (i = begin; i < size; i++) {
        stack[top] = nums[i];
        cambinate_sum(nums, size, target - nums[i], i, stack, top+1, dst); 
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int *stack = (int *)malloc(sizeof(int) * target);
    struct ArrayHead dst = {NULL, NULL, 0, 0};

//    qsort(candidates, candidatesSize, sizeof(int), cmp_int);
    cambinate_sum(candidates, candidatesSize, target, 0, stack, 0, &dst);
    free(stack);

    *returnSize        = dst.size;
    *returnColumnSizes = dst.cols;

    array_print(&dst);
    return dst.array;
}

int
main(int argc, char *argv[]) {
    int target = 0;
    int array[] = {2,3,7};
    int *colsizes;
    int retsize;
    int **pp;
    if (argc < 2) {
        printf("usage:%s target\n", argv[0]);
        return -1;
    }
    target = atoi(argv[1]);
    pp = combinationSum(array, sizeof(array)/sizeof(array[0]), target, &retsize, &colsizes);
    printf("result count: %d\n", retsize);
    return 0;
}

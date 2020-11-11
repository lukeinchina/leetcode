#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define do_swap(a, b) { \
            temp      = nums[idx];\
            nums[idx] = nums[i];\
            nums[i]   = temp;\
        }while(0)
void gen_perm(int *nums, int size, int idx, int **pp, int *count) {
    int i, temp;
    if (idx+1 == size) {
        memcpy(pp[*count], nums, sizeof(int) * size);
        *count += 1;
        return ;
    }
    for (i = idx; i < size; i++) {
        do_swap(nums[idx], nums[i]);
        gen_perm(nums, size, idx+1, pp, count);
        do_swap(nums[idx], nums[i]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, *p, **pp;
    int count = 1;
    for (i = 1; i <= numsSize; i++) {
        count *= i;
    }
    p = (int *)malloc(sizeof(int) * count);
    pp = (int **)malloc(sizeof(int *) * count);
    *returnColumnSizes = p;
    for (i = 0; i < count; i++) {
        p[i] = numsSize;
        pp[i] = (int *)malloc(sizeof(int) * numsSize);
    }
    *returnSize = count;

    /* work */
    count = 0;
    gen_perm(nums, numsSize, 0, pp, &count);

    return pp;
}

int
main(void) {
    int i, j;
    int array[] = {1, 2, 3, 4};
    int size = 0;
    int *p = NULL;
    int **pp = permute(array, 4, &size, &p);
    printf("-----%p------\n", p);
    for (i = 0; i < size; i++) {
        for (j = 0; j < p[i]; j++) {
            printf("%d ", pp[i][j]);
        }
        printf("\n");
    }
    return 0;
}

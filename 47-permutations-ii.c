#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common/array.h"

#define do_swap(a, b) { \
            temp      = nums[idx];\
            nums[idx] = nums[i];\
            nums[i]   = temp;\
        }while(0)

int can_swap(int nums[], int begin, int end) {
    for (; begin < end; begin++) {
        if (nums[begin] == nums[end]) {
            return 0;
        }
    }
    return 1;
}

void gen_perm(int *nums, int size, int idx, struct ArrayHead *head) {
    int i, temp;
    if (idx+1 == size) {
        array_append(head, nums, size);
        return ;
    }
    for (i = idx; i < size; i++) {
        if (can_swap(nums, idx, i)) {
            do_swap(nums[idx], nums[i]);
            gen_perm(nums, size, idx+1, head);
            do_swap(nums[idx], nums[i]);
        }
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    struct ArrayHead head;
    array_init(&head);

    gen_perm(nums, numsSize, 0, &head);
    *returnColumnSizes = head.cols;
    *returnSize = head.size;

    return head.array;
}

int
main(void) {
    int i, j;
    int array[] = {4, 1, 1, 4};
    int size = 0;
    int *p = NULL;
    int **pp = permuteUnique(array, 4, &size, &p);
    for (i = 0; i < size; i++) {
        for (j = 0; j < p[i]; j++) {
            printf("%d ", pp[i][j]);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>


int* majorityElement(int* nums, int numsSize, int* returnSize){
    int i,j,n1,n2, nuniq = 0;
    int less = numsSize / 3;
    int *dst = NULL;
    int uniq[2];
    int count[2] = {0, 0};
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < nuniq; j++) {
            if (uniq[j] == nums[i]) {
                count[j] += 1;
                break;
            }
        }
        /* 是重复元素, 已经计数 */
        if (j < nuniq) {
            continue;
        }

        /* 去重后还不到2个元素,直接增加 */
        if (nuniq < 2) {
            uniq[nuniq]  = nums[i];
            count[nuniq] = 1;
            nuniq++;
            continue;
        }
        /* 选择较少出现元素换出 */
        for (j = 0; j < nuniq; j++) {
            if (count[j] < 1) {
                uniq[j] = nums[i];
                count[j] = 1;
                break;
            }
        }

        if (j < nuniq) {
            continue;
        }
        count[0] -= 1;
        count[1] -= 1;
    }

    *returnSize = 0;
    if (nuniq < 1) {
        return NULL;
    } else if (1 == nuniq) {
        *returnSize = 1;
        dst = (int *)malloc(sizeof(int) * nuniq);
        dst[0] = uniq[0];
        return dst;
    }

    n1 = n2 = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == uniq[0]) {
            n1++;
        } else if (nums[i] == uniq[1]) {
            n2++;
        }
    }
    if (n1 <= less && n2 <= less) {
        return NULL;
    }
    dst = (int *)malloc(sizeof(int) * 2);
    if (n1 > less) {
        dst[*returnSize] = uniq[0];
        *returnSize += 1;
    }
    if (n2 > less) {
        dst[*returnSize] = uniq[1];
        *returnSize += 1;
    }
    return dst;
}

int
main(void) {
    // int nums[] = {3,3,1,1,1,1,2,4,4,3,3,3,4,4};
    int nums[] = {1,1,1,2,3,7,8,1,6,9};
    // int nums[] = {2,1,1,3,1,4,5,6};
    // [1,1,1,2,3,7,8,1,6,9]
    int i, size = 0;
    int *pp =  majorityElement(nums, sizeof(nums) / sizeof(nums[0]), &size);
    printf("[");
    for (i = 0; i < size; i++) {
        printf("%d ", pp[i]);
    }
    printf("]\n");
    return 0;
}

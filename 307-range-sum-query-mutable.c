#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int size;
    int *nums;
    int *sums;
    int step;
    int nstep;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    int sum, i, j;
    NumArray *obj = (NumArray *)calloc(1, sizeof(NumArray));
    obj->size = numsSize;
    obj->nums = (int *)malloc(sizeof(nums[0]) * numsSize);
    memcpy(obj->nums, nums, numsSize * sizeof(nums[0]));

    obj->step = (int)sqrt(numsSize);
    obj->step &= 0XFFFFFFF8;

    if (obj->step == 0) {
        return obj;
    }
    obj->nstep = obj->size / obj->step;
    obj->sums = (int *)malloc(sizeof(nums[0]) * obj->nstep);
    for (i = 0; i < obj->nstep; i++) {
        sum = 0;
        for (j = 0; j < obj->step; j++) {
            sum += nums[i * obj->step + j];
        }
        obj->sums[i] = sum;
    }
    return obj;
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    int idx;
    int diff = val - obj->nums[index];
    obj->nums[index] = val;

    if (0 == obj->step) {
        return ;
    }
    idx = index / obj->step;
    if (idx < obj->nstep) {
        obj->sums[idx] += diff;
    }
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int i, begin, end;
    int sum = 0;
    if (NULL == obj->sums || right - left < obj->step) {
        for (; left <= right; left++) {
            sum += obj->nums[left];
        }
        return sum;
    }
    begin = left / obj->step + (left % obj->step > 0);
    end = right / obj->step;
    for (i = left; i < begin * obj->step; i++) {
        sum += obj->nums[i];
    }
    for (i = end * obj->step; i <= right; i++) {
        sum += obj->nums[i];
    }
    for (i = begin; i < end; i++) {
        sum += obj->sums[i];
    }
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj->nums);
    if (NULL != obj->sums) {
        free(obj->sums);
    }
    free(obj);
}

int
main(void) {
    int nums[] = {100, 1, 3, 5, 7, 0, 1, 1, 1, 2, 3, 3, 3, 3, 4, 5, 2, 10, 20, 30, 40, 44, 22, 11, 20, 30, 9, 8 ,7, 6, 5, 5, 6 };
    NumArray* obj = numArrayCreate(nums, sizeof(nums) / sizeof(nums[0]));
    numArrayUpdate(obj, 1, 10);
    numArrayUpdate(obj, 1, -10);
    printf("%d\n", numArraySumRange(obj, sizeof(nums) / sizeof(nums[0]) / 3,  sizeof(nums) / sizeof(nums[0]) / 2));
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *nums;
    int size;

    int *sums;
    int nstep;
    int step;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    int i, j, sum;

    NumArray *p = (NumArray *)calloc(1, sizeof(NumArray));
    p->size     = numsSize;
    p->nums      = (int *)malloc(sizeof(nums[0]) * numsSize);
    memcpy(p->nums, nums, sizeof(nums[0]) * numsSize);

    if (numsSize < 16) {
        return p;
    }
    p->step  = (int)sqrt(numsSize);
    p->nstep = p->step;
    p->sums  = (int *)malloc(sizeof(nums[0]) * p->nstep);
    for (i = 0; i < p->nstep; i++) {
        sum = 0;
        for (j = 0; j < p->step; j++) {
            sum += nums[i * p->step + j];
        }
        p->sums[i] = sum;
    }
    return p;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int begin, end, i, sum = 0;
    if (NULL == obj->sums || right - left < obj->step) {
        for (; left <= right; left++) {
            sum += obj->nums[left];
        }
        return sum;
    }
    begin = left / obj->step + (left % obj->step != 0);
    end   = right / obj->step;

    for (i = left; i < obj->step * begin; i++) {
        sum += obj->nums[i];
    }
    for (i = begin; i < end; i++) {
        sum += obj->sums[i];
    }
    for (i = end * obj->step; i <= right; i++) {
        sum += obj->nums[i];
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
main(int argc, char *argv[]) {
    int nums[100], sum;
    if (argc < 3) {
        printf("usage:%s left, right\n", argv[0]);
        return 0;
    }
    NumArray *obj = numArrayCreate(nums, sizeof(nums) / sizeof(nums[0]));
    sum = numArraySumRange(obj, atoi(argv[1]), atoi(argv[2]));
    return 0; 
}

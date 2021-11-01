#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int size;
    int capacity;
    int *nums;
} MedianFinder;


MedianFinder* medianFinderCreate() {
    MedianFinder *p = (MedianFinder *)calloc(1, sizeof(MedianFinder));
    p->capacity = 8;
    p->nums = (int *)calloc(p->capacity, sizeof(int));
    return p;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    int i;
    if (obj->size >= obj->capacity) {
        obj->capacity *= 2;
        obj->nums = (int *)realloc(obj->nums, obj->capacity * sizeof(int));
    }
    for (i = obj->size; i > 0 && num < obj->nums[i-1]; i--) {
        obj->nums[i] = obj->nums[i-1];
    }
    obj->nums[i] = num;
    obj->size++;
}

double medianFinderFindMedian(MedianFinder* obj) {
    double v = obj->nums[obj->size >> 1];
    if (obj->size % 2 == 0) {
        v += obj->nums[(obj->size >> 1) - 1];
        v /= 2;
    }
    return v;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}

int 
main(void) {
    int i;
    int nums[] = {6, 10, 2, 6, 5, 0, 6, 3, 1, 0, 0};
    double v;
    MedianFinder *obj = medianFinderCreate();
    for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        medianFinderAddNum(obj, nums[i]);
        v = medianFinderFindMedian(obj);
        printf("median:%f\n", v);
    }
}

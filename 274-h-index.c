#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int hIndex(int* citations, int citationsSize){
    int i, h = 0;
    qsort(citations, citationsSize, sizeof(int), cmp_int);
    for (i = 0; i < citationsSize && citations[i] >= i+1; i++) {
        h = i+1;
    }
    return h;
}

void print_array(const int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", array[i], i+1 == size ? '\n' : '\t');
    }
}

int
main(int argc, char *argv[]) {
    int nums[] = {1, 1, 2};
    int h;
    print_array(nums, sizeof(nums) / sizeof(nums[0]));
    h = hIndex(nums, sizeof(nums) / sizeof(nums[0]));
    print_array(nums, sizeof(nums) / sizeof(nums[0]));
    printf("h-index:%d\n", h);
    return 0;
}

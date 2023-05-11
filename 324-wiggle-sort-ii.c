#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(const int *nums, int size);

int compare(const void *l, const void *r) {
    return *(int *)l - *(int *)r;
}

void reverse_array(int *start, int *end) {
    int val;
    while (start < end) {
        val = *start;
        *start = *end;
        *end = val;

        start++;
        end--;
    }
}

void wiggleSort(int* nums, int numsSize){
    int i, j, idx;
    int *buff = (int *)malloc(sizeof(int) * numsSize);
    qsort(nums, numsSize, sizeof(nums[0]), compare);
    reverse_array(nums, nums + (numsSize+1) / 2 - 1);
    reverse_array(nums + (numsSize+1) / 2, nums + numsSize - 1);

    idx = i = 0;
    j = (numsSize+1) / 2;
    while (j < numsSize) {
        buff[idx++] = nums[i++];
        buff[idx++] = nums[j++];
    }
    if (i < (numsSize +1 ) / 2) {
        buff[idx++] = nums[i++];
    }
    for (i = 0; i < idx; i++) {
        nums[i] = buff[i];
    }
    free(buff);
    return;
}


void print_array(const int *nums, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1 == size ? '\n' : '\t');
    }
}

int
main(void) {
    int nums[] = {1,1,2,1,2,2,1};
    int array[] = {1,4,3,4,1,2,1,3,1,3,2,3,3};
    wiggleSort(nums, sizeof(nums) / sizeof(nums[0]));
    print_array(nums, sizeof(nums) / sizeof(nums[0]));
    wiggleSort(array, sizeof(array) / sizeof(array[0]));
    print_array(array, sizeof(array) / sizeof(array[0]));
    return 0;
}

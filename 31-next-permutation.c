#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) do{ temp = a; a = b; b = temp;}while(0)
int compare(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

void print_array(const int *nums, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1==size ? '\n' : '\t');
    }
    return;
}

void swap_all(int *nums, int size) {
    int temp,i;
    for (i = 0; i < size/2; i++) {
        swap(nums[i], nums[size-1-i]);
    }
}

void nextPermutation(int* nums, int numsSize){
    int i, j, temp,  min, pos;
    for (i = numsSize-1; i > 0; i--) {
        if (nums[i] > nums[i-1]) {
            min = nums[i];
            pos = i;
            for (j = i+1; j < numsSize; j++) {
                if (nums[j] < min && nums[j] > nums[i-1]) {
                    min = nums[j];
                    pos = j;
                }
            }
            swap(nums[i-1], nums[pos]);
            qsort(nums+i, numsSize-i, sizeof(int), compare);
            return;
        }
    }
    swap_all(nums, numsSize);
}

int
main(int argc, char *argv[]){
    int nums[16];
    int i;
    if (argc < 2) {
        printf("usage:%s n1 n2 n3 ... \n", argv[0]);
        return -1;
    }
    for (i = 0; i < argc-1; i++) {
        nums[i] = atoi(argv[i+1]);
    }
    print_array(nums, argc-1);
    nextPermutation(nums, argc-1);
    print_array(nums, argc-1);
    return 0;
}

#include <stdio.h>

#define swap(a, b) do {tmp = a; a = b; b = tmp;} while(0)
void print_array(int *nums, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1 == size ? '\n' : ' ');
    }
    printf("----------\n");
}

int removeDuplicates(int* nums, int numsSize){
    int i, idx = 1;
    if (numsSize < 3) {
        return numsSize;
    }
    for (i = 2; i < numsSize; i++) {
        if (nums[i] != nums[idx-1]) {
            nums[++idx] = nums[i];
        }
    }
    return idx+1;
}


int
main(void) {
    int size = 0;
    int nums[] = {0,0,1,1,1,1,2,3,3};
    print_array(nums, sizeof(nums)/sizeof(nums[0]));
    size = removeDuplicates(nums, sizeof(nums)/sizeof(nums[0]));
    print_array(nums, size);
    return 0;
}

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int i, idx;
    idx = i = 0;
    while (i < numsSize) {
        nums[idx] = nums[i];
        /*skip dup element */
        for (i += 1; i < numsSize && nums[idx] == nums[i]; i++) {
        }
        idx += 1;
    }
    return idx;
}

void print_array(int *array, int size) {
    int i = 0; 
    for (i = 0; i < size; i++) {
        printf("%d%c", array[i], (i+1 == size ? '\n' : '\t'));
    }
}

int main(void) {
    int array[] = {0,0,1,1,1,2,2,3,3,4};
    int size = sizeof(array) / sizeof(array[0]);
    print_array(array, size);
    size = removeDuplicates(array, size);
    print_array(array, size);
    size = removeDuplicates(array, size);
    print_array(array, size);
    return 0;
}

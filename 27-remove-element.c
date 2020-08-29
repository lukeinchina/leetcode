#include <stdio.h>


int removeElement(int* nums, int numsSize, int val){
    int i, idx;
    i = idx = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[idx++] = nums[i];
        }
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
    int array[] = {0,1,2,2,3,0,4,2};
    int size = sizeof(array) / sizeof(array[0]);
    print_array(array, size);
    size = removeElement(array, size, 2);
    print_array(array, size);
    size = removeElement(array, size, 0);
    print_array(array, size);
    return 0;
}

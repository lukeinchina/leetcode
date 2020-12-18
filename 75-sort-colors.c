#include <stdio.h>

#define swap(a, b) do {tmp = a; a = b; b = tmp;} while(0)
void print_array(int *nums, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1 == size ? '\n' : ' ');
    }
    printf("----------\n");
}

void sortColors(int* nums, int numsSize){
    int *left = nums;
    int *right = nums + numsSize - 1;
    int *mid   = left;
    int tmp;
    while (left < right && mid <= right) {
        if (0 == *left) {
            left++;
            continue;
        } else if (2 == *right) {
            right--;
            continue;
        }
        
        /* init mid */
        if (mid < left) {
            mid = left;
        } 

        if (0 == *mid) {
            swap(*mid, *left);
            left++;
        } else if (2 == *mid) {
            swap(*mid, *right);
            right--;
        } else {
            /*  *mid == 1 */
            mid++;
        }
    }
}

int
main(void) {
    // int nums[] = {2,0,2,1,1,0};
    int nums[] = {2};
    print_array(nums, sizeof(nums)/sizeof(nums[0]));
    sortColors(nums, sizeof(nums)/sizeof(nums[0]));
    print_array(nums, sizeof(nums)/sizeof(nums[0]));
    return 0;
}

#include <stdio.h>

#define min(a, b) ((a) > (b) ? (b) : (a))

int max_index_left(int *nums, int left, int right) {
    int i, max, index;
    max   = -1;
    index = -1;

    /* 跳过递减 */
    for (i = right-1; i >= 0 && nums[i] <= nums[i+1]; i--) {
    }
    for (; i >= 0; i--) {
        if (nums[i] >= max) {
            max   = nums[i]; 
            index = i;
        }
    }
    return index;
}

int max_index_right(int *nums, int left, int right) {
    int i, max, index;
    max   = -1;
    index = -1;

    /* 跳过递减 */
    for (i = left+1; i <= right && nums[i-1] >= nums[i]; i++) {
    }
    for (; i <= right; i++) {
        if (nums[i] >= max) {
            max   = nums[i]; 
            index = i;
        }
    }

    return index;
}

int calc_area(int *nums, int left, int right) {
    int area = 0;
    int i;
    int min = min(nums[left], nums[right]);
    for (i = left; i <= right; i++) {
        if (nums[i] > min) {
            continue;
        }
        area += (min - nums[i]);
    }
    return area;
}

int trap(int* height, int heightSize){
    int peak, left, right;
    int area = 0;

    right = peak = max_index_left(height, 0, heightSize-1);

    /* left */
    while (right > -1) {
        left = max_index_left(height, 0, right);
        if (left < 0) {
            break;
        }
        area += calc_area(height, left, right);
        right = left;
    }
    /* right */
    left  = peak;
    while (left > -1) {
        right = max_index_right(height, left, heightSize-1);
        if (right < 0) {
            break;
        }
        area += calc_area(height, left, right);
        left = right;
    }

    return area;
}

int
main(void) {
    int array[] = {4,2,0,3,2,5};
    // int array[] = {5,4,1,2};
    // int array[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("%d\n", trap(array, sizeof(array)/sizeof(array[0])));
    return 0;
}

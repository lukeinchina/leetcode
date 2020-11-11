#include <stdio.h>

int max_index(int *nums, int size) {
    int i, max;
    max = -1;
    for (i = 0; i < size; i++) {
        if (nums[i] > max) {
            max  = nums[i]; 
        }
    }
    return max;
}

int trap(int* height, int heightSize){
    int peak, left, right;
    peak = max_index(height, heightSize);
    left = max_index(height, peak);
    right = max_index(height+peak+1, heightSize - peak - 1);
}
/*
int trap(int* height, int heightSize){
    // left, right, bottom
    int l, r, b;
    for (l = 0; l+1 < heightSize && height[l] <= height[l+1]; l++) {}
    while (l < heightSize) {
        for (b = l+1; b+1 < heightSize && height[b+1] <= height[b]; b++) {}
        for (r = b+1; r+1 < heightSize && height[r] <= height[r+1]; r++) {}
        if (r < heightSize) {
            printf("[%d:%d:%d] [%d %d %d]\n", l, b, r, height[l], height[b], height[r]);
        }
        l = r;
    }
    return 0;
}
*/

int
main(void) {
    int array[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("%d\n", trap(array, sizeof(array)/sizeof(array[0])));
    return 0;
}

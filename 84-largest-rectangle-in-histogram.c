#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(int* heights, int heightsSize){
    int left, right, i, end = heightsSize;
    int area = 0;
    for (i = 0; i < end; i++) {
        if (heights[i] == 0) {
            continue;
        }
        left = right = i;
        while (right < end && heights[right] >= heights[i]) {
            right++;
        }
        while (left >= 0 && heights[left] >= heights[i]) {
            left--;
        }
        if ((right - left - 1) * heights[i] > area) {
            area = (right - left - 1) * heights[i];
        }
    }
    return area;
}

int
main(int argc, char *argv[]) {
    int nums[] = {2,1,5,6,2,3};
    printf("%d\n",  largestRectangleArea(nums, sizeof(nums)/sizeof(nums[0])));
    return 0;
}

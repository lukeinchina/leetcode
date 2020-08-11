#include <stdio.h>

int maxArea(int* height, int heightSize){
    int i, j, area, max;
    i = max = 0;
    j = heightSize - 1;
    while (i < j) {
        if (height[i] < height[j]) {
            area = (j - i) * height[i];
            i++;
        } else {
            area = (j - i) * height[j];
            j--;
        }
        if (max < area) {
            max = area;
        }
    }
    return max;
}

int main(void) {
    int array[] = {1,8,6,2,5,4,8,3,7};
    printf("%d\n", maxArea(array, 9));
    return 0;
}

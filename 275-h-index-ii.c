#include <stdio.h>
#include <stdlib.h>


int hIndex(int* citations, int citationsSize){
    int left, right, mid;
    int h = citations[citationsSize-1] > 0 ? 1 : 0;
    left = 0;
    right = citationsSize - 1;
    while (left < right) {
        mid = (left + right) / 2;
        if (citations[mid] >= citationsSize - mid) {
            right = mid;
            h = citationsSize - mid;
        } else {
            left = mid + 1;
        }
    }
    return h;
}

void print_array(const int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", array[i], i+1 == size ? '\n' : '\t');
    }
}

int
main(int argc, char *argv[]) {
    int nums[] = {3, 3};
    int h;
    print_array(nums, sizeof(nums) / sizeof(nums[0]));
    h = hIndex(nums, sizeof(nums) / sizeof(nums[0]));
    print_array(nums, sizeof(nums) / sizeof(nums[0]));
    printf("h-index:%d\n", h);
    return 0;
}

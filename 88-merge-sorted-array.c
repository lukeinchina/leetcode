#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    while (m > 0 && n > 0) {
        if (nums1[m-1] < nums2[n-1]) {
            nums1[m+n-1] = nums2[n-1];
            --n;
        } else {
            nums1[m+n-1] = nums1[m-1];
            --m;
        }
    }
    for (; n > 0; n--) {
        nums1[n-1] = nums2[n-1];
    }
}

int
main(int argc, char *argv[]) {
    int i;
    int nums[] = {1,2,3,0,0,0};
    int nums2[] = {1, 2, 2, 3, 5, 6};
    merge(nums, 6, 0, nums2, 6, 6);
    for (i = 0; i < 6; i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}

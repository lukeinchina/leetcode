#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int pre, cur, mid, i, j;
    mid = (nums1Size + nums2Size) / 2;
    i = j = 0;
    while (i < nums1Size || j < nums2Size) {
        if (i + j == mid) {
            break;
        }
        if (i == nums1Size) {
            pre = nums2[j++];
        } else if (j == nums2Size) {
            pre = nums1[i++];
        } else if (nums1[i] < nums2[j]) {
            pre = nums1[i++];
        } else {
            pre = nums2[j++];
        }
    }
    printf("i=%d, j=%d\n", i, j);
    if (i == nums1Size) {
        cur = nums2[j];
    } else if (j == nums2Size) {
        cur = nums1[i];
    } else {
        cur = (nums1[i] < nums2[j] ? nums1[i] : nums2[j]);
    }
    if ((nums1Size + nums2Size) % 2) {
        return cur;
    } else {
        return (pre + cur) / 2.0;
    }
}

int main(void) {
    int array1[] = {1, 3};
    int array2[] = {2, 4, 6, 8, 10, 12, 14};
    printf("%f\n", findMedianSortedArrays(array1, 0, array2, 1));
    return 0;
}

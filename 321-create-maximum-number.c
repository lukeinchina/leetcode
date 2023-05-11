#include <stdlib.h>

/*
 * Create the maximum number of length k <= m + n from digits of the two numbers.
 * The relative order of the digits from the same array must be preserved.
 * Return an array of the k digits representing the answer.
 * Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5 Output: [9,8,6,5,3]
*/
int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize){
    int i, j, count = 0;
    int off1 = -1;
    int off2 = -1;
    int *dst = (int *)malloc(sizeof(nums1[0]) * k);
    *returnSize = k;

    for (i = 9; i >= 0; i--) {
        for (j = off1+1; j < nums1Size; j++) {
            if (nums1[j] == i) {
                dst[count++] = nums1[j];
                if (count == k) {
                    return dst;
                }
            }
        }
        for (j = off2+1; j < nums2Size; j++) {
            if (nums2[j] == i) {
                dst[count++] = nums2[j];
                if (count == k) {
                    return dst;
                }
            }
        }
    }
    return dst;
}

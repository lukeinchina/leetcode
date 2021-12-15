#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int i , j, n;
    int *nums = NULL;
    qsort(nums1, nums1Size, sizeof(nums1[0]), cmp_int);
    qsort(nums2, nums2Size, sizeof(nums2[0]), cmp_int);

    n = i = j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            n++;
            i++;
            j++;
        }
    }
    *returnSize = n;
    nums = (int *)malloc(sizeof(nums1[0]) * n);

    n = i = j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            nums[n++] = nums1[i++];
            j++;
        }
    }
    return nums;
}

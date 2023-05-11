#include <stdio.h>
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int i, n = 0;
    int map1[1002] = {0};
    int map2[1002] = {0};
    int *dst = NULL;
    for (i = 0; i < nums1Size; i++) {
        map1[nums1[i]] = 1;
    }
    for (i = 0; i < nums2Size; i++) {
        map2[nums2[i]] = 1;
    }
    for (i = 0; i < 1001; i++) {
        if (map1[i] & map2[i]) {
            n++;
        }
    }
    dst = (int *)malloc(n * sizeof(int));
    *returnSize = n;

    n = 0;
    for (i = 0; i < 1001; i++) {
        if (map1[i] & map2[i]) {
            dst[n++] = i;
        }
    }
    return dst;
}

int
main(int argc, char *argv[]) {
    int i, size;
    int nums1[] = {4,7,9,7,6,7};
    int nums2[] = {5,0,0,6,1,6,2,2,4};
    int *p = intersection(nums1, sizeof(nums1)/sizeof(nums1[0]),
            nums2, sizeof(nums2)/sizeof(nums2[0]), &size);
    for (i = 0; i < size; i++) {
        printf("%d%c", p[i], i+1 == size ? '\n' : ',');
    }
    return 0;
}

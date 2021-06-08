#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    int j, i = 0;
    for (i = 0; i < numsSize; i = j+1) {
        for (j = i; j+1 < numsSize; j++) {
            if (nums[j]+1 != nums[j+1]) {
                break;
            }
        }
        if (j > i) {
            printf("%d->%d\n", nums[i], nums[j]);
        } else {
            printf("%d\n", nums[j]);
        }
    }
    return NULL;
}

int
main(void) {
    int array[] = {0,2,3,4,6,8,9};
    int i, size = 0;
    char **pp = summaryRanges(array, sizeof(array) / sizeof(array[0]), &size);
    printf("[\n");
    for (i = 0; i < size; i++) {
        printf("%s", pp[i]);
    }
    printf("]\n");
    return 0;
}

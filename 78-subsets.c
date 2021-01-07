#include <stdio.h>
#include <stdlib.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, size, n, k, total, index;
    int **pp, *cols;
    total = (1 << numsSize);
    pp    = (int **)malloc(sizeof(int *) * total);
    cols  = (int *)malloc(sizeof(int) * total);
    for (i = 0; i < total; i++) {
        size = 0;
        for (n = i; n != 0; n &= (n-1)) {
            size += 1;
        }
        cols[i] = size; 
        pp[i]   = (int *)malloc(sizeof(int) * size);
        for (index = 0, k = 0; k < numsSize; k++) {
            if ((1 << k) & i) {
                pp[i][index++] = nums[k];
            }
        }
    }
    *returnSize        = total;
    *returnColumnSizes = cols;
    return pp;
}

int
main(int argc, char *argv[]) {
    int nums[] = {1, 2, 3};
    int i, j, size, *cols;
    int **pp = subsets(nums, sizeof(nums)/sizeof(nums[0]), &size, &cols);
    printf("%d\n", size);
    for (i = 0; i < size && NULL != pp; i++) {
        if (cols[i] == 0) {
            printf("[]\n");
        }
        for (j = 0; j < cols[i]; j++) {
            printf("%d%c", pp[i][j], j+1 == cols[i] ? '\n' : '\t');
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int i, j, min = INT_MAX;
    int *prev, *curr, *tmp;
    if ( triangleSize < 2 ) {
        return triangle[0][0];
    }
    prev = (int *)malloc(sizeof(int) * triangleColSize[triangleSize-1]);
    curr = (int *)malloc(sizeof(int) * triangleColSize[triangleSize-1]);
    for (j = 0; j < triangleColSize[triangleSize-1]; j++) {
        prev[j] = curr[j] = INT_MAX;
    }
    prev[0] = triangle[0][0];
    for (i = 0; i+1 < triangleSize; i++) {
        for (j = 0; j < triangleColSize[i]; j++) {
            if (prev[j] + triangle[i+1][j] < curr[j]) {
                curr[j] = prev[j] + triangle[i+1][j]; 
            }
            if (prev[j] + triangle[i+1][j+1] < curr[j+1]) {
                curr[j+1] = prev[j] + triangle[i+1][j+1]; 
            }
        }
        tmp = prev;
        prev = curr;
        curr = tmp;
        for (j = 0; j < triangleColSize[i]; j++) {
            curr[j] = INT_MAX;    
        }
    }
    i = triangleSize - 1;
    for (j = 0; j < triangleColSize[i]; j++) {
        min = (min > prev[j] ? prev[j] : min);
    }
    free(prev);
    free(curr);
    return min;
}

int
main(void) {
    int cases[][4] = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    int *array[] = {cases[0], cases[1], cases[2], cases[3]};
    int cols[]   = {1, 2, 3, 4};
    printf("%d\n", minimumTotal(array, 4, cols));
    return 0;
}

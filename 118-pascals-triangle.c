#include <stdlib.h>

int** 
generate(int numRows, int* returnSize, int** returnColumnSizes){
    int i, j, n = numRows;
    int **pp = (int **)malloc(sizeof(int *) * numRows);
    int *cols = (int *)malloc(sizeof(int) * numRows);
    for (i = 0; i < n; i++) {
        cols[i]  = i+1;
        pp[i]    = (int *)malloc(sizeof(int) * (i+1));
        pp[i][0] = pp[i][i] = 1;
        for (j = 1; j < i; j++) {
            pp[i][j] = pp[i-1][j-1] + pp[i-1][j];
        }
    }
    *returnColumnSizes = cols;
    *returnSize = numRows;
    return pp;
}

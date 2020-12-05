#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int minPathSum(int** grid, int gridSize, int* gridColSize){
    int i, j, min, *prev, *curr, *tmp;
    int col_size = gridColSize[0];
    int *buff = (int *)malloc(sizeof(int) * col_size * 2);
    prev = buff;
    curr = buff + col_size;
    for (i = 0; i < col_size; i++) {
        prev[i] = (i == 0) ? grid[0][0] : (prev[i-1]+grid[0][i]);
    }
    for (i = 1; i < gridSize; i++) {
        curr[0] = grid[i][0] + prev[0];
        for (j = 1; j < col_size; j++) {
            curr[j] = (curr[j-1] > prev[j] ? prev[j] : curr[j-1]) + grid[i][j];
        }
        /* swap */
        tmp  = curr;
        curr = prev;
        prev = tmp;
    }
    min = prev[col_size-1];
    free(buff);
    return min;
}

int
main(void) {
    int array[][3] = {{1,3,1},{1,5,1},{4,2,1}};
    int *grid[] = {array[0], array[1], array[2]};
    int cols[]  = {3, 3, 3};
    printf("%d\n", minPathSum(grid, 3, cols));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void dfs(char **grid, int row, int col, int i, int j) {
    if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0';
    dfs(grid, row, col, i-1, j);
    dfs(grid, row, col, i+1, j);
    dfs(grid, row, col, i, j-1);
    dfs(grid, row, col, i, j+1);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int i,j, count = 0;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, gridSize, gridColSize[i], i, j);
                count += 1;
            }
        }
    }
    return count;
}

int
main(void) {
    char matrix1[][5] = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    char matrix[][5] = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    char *grid[] = {matrix[0], matrix[1], matrix[2], matrix[3]};
    int cols[] = {5, 5, 5, 5};
    int n = numIslands(grid, 4, cols);
    printf("%d\n", n);
    return 0;
}

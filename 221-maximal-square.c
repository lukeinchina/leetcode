#include <stdio.h>
#include <stdlib.h>

int **
create_matrix(int row, int col) {
    int i;
    int ** matrix = (int **)malloc(sizeof(int *) * row);
    for (i = 0; i < row; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * col);
    }
    return matrix;
}

void free_matrix(int **matrix, int row) {
    int i;
    for (i = 0; i < row; i++) {
        free(matrix[i]);
        matrix[i] = 0;
    }
    free(matrix);
}

void print_matrix(int **matrix, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d%c", matrix[i][j], j+1 == col ? '\n': '\t');
        }
    }
}

int maximalSquare_dp(char** matrix, int matrixSize, int* matrixColSize){
    int i,j, tmp, col = matrixColSize[0];
    int **dp = create_matrix(matrixSize, col);
    int max = 0;
    for (i = 0; i < matrixSize; i++) {
        dp[i][0] = (matrix[i][0] == '0' ? 0 : 1);
        if (dp[i][0]) {
            max = 1;
        }
    }
    for (i = 0; i < col; i++) {
        dp[0][i] = (matrix[0][i] == '0' ? 0 : 1);
        if (dp[0][i]) {
            max = 1;
        }
    }
    for (i = 1; i < matrixSize; i++) {
        for (j = 1; j < col; j++) {
            if (matrix[i][j] == '0') {
                dp[i][j] = 0;
                continue;
            }
            if (dp[i-1][j] == dp[i][j-1]) {
                tmp = dp[i-1][j];
                dp[i][j] = tmp + (dp[i-tmp][j-tmp] != 0);
            } else {
                dp[i][j] = 1 + (dp[i-1][j] > dp[i][j-1] ? dp[i][j-1] : dp[i-1][j]);
            }
            if (dp[i][j] > max) {
                max = dp[i][j];
            }
        }
    }
    print_matrix(dp, matrixSize, col);
    free_matrix(dp, matrixSize);
    return max * max;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int i, j, k, col = matrixColSize[0];
    int w, area, max = 0;
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < col; j++) {
            if ('0' == matrix[i][j]) {
                continue;
            }
            area = 1;
            for (w = 2; i+w <= matrixSize && j+w <= col; w++) {
                for (k = 0; k < w; k++) {
                    if (matrix[i+w-1][j+k] == '0' || matrix[i+k][j+w-1] == '0') {
                        break;
                    }
                }
                if (k != w) {
                    break;
                }
                area = w * w;
            }
            max = max < area ? area : max;
        }
    }
    return max;
}

int
main(void) {
    char matrix[][5] = {
        {'1','1','1','1','0'},
        {'1','1','1','1','0'},
        {'1','1','1','1','1'},
        {'1','1','1','1','1'},
        {'0','0','1','1','1'}};
    char *strs[] = {matrix[0], matrix[1], matrix[2], matrix[3], matrix[4]};
    int cols[]   = {5, 5, 5, 5, 5};
    int area     = maximalSquare(strs, 5, cols);
    printf("%d\n", area);
    printf("----\n");
    printf("%d\n", maximalSquare_dp(strs, 5, cols));
    return 0;
}

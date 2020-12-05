#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int row, row_end;
    int col, col_end;
    int i, *array, index = 0;
    *returnSize = matrixSize * matrixColSize[0];
    array = (int *)malloc(sizeof(int) * *returnSize);
    col = row = 0;
    row_end = matrixSize -1;
    col_end = matrixColSize[0] - 1;
    while (row <= row_end && col <= col_end) {
        /* top row */
        for (i = col; i <= col_end; i++) {
            array[index++] = matrix[row][i];
        }
        /* right col  */
        for (i = row+1; i < row_end; i++) {
            array[index++] = matrix[i][col_end];
        }
        /* bottom row */
        if (row < row_end) {
            for (i = col_end; i >= col; i--) {
                array[index++] = matrix[row_end][i];
            }
        }
        /* left row   */
        if (col < col_end) {
            for (i = row_end-1; i > row; i--) {
                array[index++] = matrix[i][col];
            }
        }
        row += 1;
        col += 1;
        row_end -= 1;
        col_end -= 1;

    }
    return array;
}

int
main(void) {
    int i;
    int size = 0;
    int matrix[][3] = {
        {1,2,3}, {4, 5,6},{7,8,9}
    };
    /*
    int matrix[][4] = {
        {1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16}
    };
    int *pp[] = {matrix[0], matrix[1], matrix[2], matrix[3]};
    int cols[] = {4, 4, 4, 4};
    */
    int *pp[] = {matrix[0], matrix[1], matrix[2]};
    int cols[] = {3, 3, 3};
    int *p = spiralOrder(pp, 3, cols, &size);
    printf("------\n");
    for (i = 0; i < size; i++) {
        printf("%d%c", p[i], i+1== size ? '\n' : ' ');
    }
    return 0;
}

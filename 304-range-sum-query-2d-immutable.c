#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int **matrix;
    int row;
    int col;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, sum;
    NumMatrix *obj = (NumMatrix *)malloc(sizeof(NumMatrix));
    obj->row = matrixSize;
    obj->col = matrixColSize[0];
    obj->matrix = (int **)malloc(sizeof(int *) * obj->row);
    for (i = 0; i < obj->row; i++) {
        obj->matrix[i] = (int *)malloc(sizeof(int) * obj->col);
    }

    sum = 0;
    for (i = 0; i < obj->col; i++) {
        sum += matrix[0][i];
        obj->matrix[0][i] = sum;
    }
    sum = 0;
    for (i = 0; i < obj->row; i++) {
        sum += matrix[i][0];
        obj->matrix[i][0] = sum;
    }

    for (i = 1; i < obj->row; i++) {
        for (j = 1; j < obj->col; j++) {
            obj->matrix[i][j] = obj->matrix[i-1][j] + obj->matrix[i][j-1] - \
                obj->matrix[i-1][j-1] + matrix[i][j];
        }
    }
    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    if (0 == row1 && 0 == col1) {
        return obj->matrix[row2][col2];
    } else if (row1 > 0 && col1 > 0) {
        return obj->matrix[row2][col2] + obj->matrix[row1-1][col1-1] \
                - obj->matrix[row1-1][col2] - obj->matrix[row2][col1-1];
    } else if (0 == row1) {
        return obj->matrix[row2][col2]  - obj->matrix[row2][col1-1];
    } else {
        return obj->matrix[row2][col2]  - obj->matrix[row1-1][col2];
    }
}

void numMatrixFree(NumMatrix* obj) {
    int i;
    for (i = 0; i < obj->row; i++) {
        free(obj->matrix[i]);
    }
    free(obj->matrix);
    free(obj);
}

int
main(void) {
    int array[5][5] = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1}, 
        {1, 2, 0, 1, 5}, 
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};
    int *ptrs[5] = {array[0], array[1], array[2], array[3], array[4]};
    int cols[5] = {5,5,5,5,5};
    NumMatrix *obj = numMatrixCreate(ptrs, 5, cols);
    printf("%d\n", numMatrixSumRegion(obj, 2, 1, 4, 3));
    printf("%d\n", numMatrixSumRegion(obj, 1, 1, 2, 2));
    printf("%d\n", numMatrixSumRegion(obj, 1, 2, 2, 4));
    printf("%d\n", numMatrixSumRegion(obj, 3, 3, 3, 3));
    printf("%d\n", numMatrixSumRegion(obj, 4, 0, 4, 3));
    printf("%d\n", numMatrixSumRegion(obj, 0, 2, 2, 4));
    return 0;
}

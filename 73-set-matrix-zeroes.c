#include <stdio.h>

void print_array(int **matrix, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d%c", matrix[i][j], j+1 == col ? '\n' : ' ');
        }
    }
    printf("-----------------\n");
}

/* flag == 1: set row; flag == 2: set col */
void set_matrix_zero(int **matrix, int row, int col, int index, int flag) {
    int i;
    if (1 == flag) {
        for (i = 0; i < col; i++) {
            matrix[index][i] = 0;
        }
    } else if (2 == flag) {
        for (i = 0; i < row; i++) {
            matrix[i][index] = 0;
        }
    }
}

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, row, col, row0,col0;
    row = matrixSize;
    col = matrixColSize[0];
    row0 = col0 = 0;
    /* 第一行 */
    for (i = 0; i < col; i++) {
        if (matrix[0][i] == 0) {
            row0 = 1;
            break;
        }
    }
    /* 第一列 */
    for (i = 0; i < row; i++) {
        if (matrix[i][0] == 0) {
            col0 = 1;
            break;
        }
    }
    /* 记录每一行是否有0元素 */
    for (i = 1; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                break;
            }
        }
    }
    /* 记录每一列是否有 0元素 */
    for (i = 1; i < col; i++) {
        for (j = 0; j < row; j++) {
            if (matrix[j][i] == 0) {
                matrix[0][i] = 0;
                break;
            }
        }
    }
    for (i = 1; i < row; i++) {
        if (matrix[i][0] == 0) {
            set_matrix_zero(matrix, row, col, i, 1);
        }
    }
    for (i = 1; i < col; i++) {
        if (matrix[0][i] == 0) {
            set_matrix_zero(matrix, row, col, i, 2);
        }
    }
    if (row0) {
        set_matrix_zero(matrix, row, col, 0, 1);
    }
    if (col0) {
        set_matrix_zero(matrix, row, col, 0, 2);
    }
}

int
main(int argc, char *argv[]){
    // int array[][4] = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    int array[][3] = {{1,1,1}, {1,0,1,}, {1,1,1}};
    int *pp[] = {array[0], array[1], array[2]};
    int cols[] = {3, 3, 3};
    print_array(pp, 3, 3);
    setZeroes(pp, sizeof(pp)/sizeof(pp[0]), cols);
    print_array(pp, 3, 3);
    return 0;
}

#include <stdio.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i,j,size2,size1;
    int tmp1,tmp2,tmp3;
    for (i = 0; i < matrixSize/2; i++) {
        size1 = matrixSize;
        size2 = matrixColSize[i];
        for (j = i; j < size2-i-1; j++) {
            tmp1 = matrix[j][size2-1-i];
            tmp2 = matrix[size1-1-i][size2-1-j];
            tmp3 = matrix[size2-1-j][i];
            matrix[j][size2-1-i] = matrix[i][j];
            matrix[size1-1-i][size2-1-j] = tmp1;
            matrix[size2-1-j][i] = tmp2;
            matrix[i][j] = tmp3;
        }
    }
}

void print_matrix(int **matrix, int size, int row_size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < row_size; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int
main(int argc, char *argv[]) {
    int matrix[3][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
    };
    int *pp[3] = {*matrix, *(matrix+1), *(matrix+2)};
    int sizes[3] = {3, 3, 3};
    rotate(pp, 3, sizes);
    print_matrix(pp, 3, 3);
    return 0;
}

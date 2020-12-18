#include <stdio.h>
#include <stdlib.h>

void print_array(int **matrix, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d%c", matrix[i][j], j+1 == col ? '\n' : ' ');
        }
    }
    printf("-----------------\n");
}

int searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int col, left, right, mid, x;
    if (matrixSize < 1) {
        return 0;
    }
    col = matrixColSize[0];
    left = 0;
    right = matrixSize * col - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        x = matrix[mid/col][mid%col];
        if (x > target) {
            right = mid - 1;
        }else if (x < target) {
            left = mid + 1;
        }else {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int array[][4] = {{1,3,5,7},  {10,11,16,20}, {23,30,34,50}};
    int *pp[] = {array[0], array[1], array[2]};
    int cols[] = {4, 4, 4};
    if (argc < 2) {
        printf("usage:%s k\n", argv[0]);
        return -1;
    }
    print_array(pp, 3, 4);
    printf("%d\n", searchMatrix(pp, sizeof(pp)/sizeof(pp[0]), cols, atoi(argv[1])));
    return 0;
}

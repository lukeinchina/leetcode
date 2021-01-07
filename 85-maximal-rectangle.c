#include <stdio.h>
#include <stdlib.h>

void print_array(char **matrix, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%c%c", matrix[i][j], j+1 == col ? '\n' : ' ');
        }
    }
    printf("-----------------\n");
}

int max_rect(char **matrix, int rb, int cb, int row, int col) {
    int i, j, tmp, area = 0;
    for (i = rb; i < row && '1' == matrix[i][cb]; i++) {
        for (j = cb; j < col && '1' == matrix[i][j]; j++) {}
        tmp = (j-cb) * (i+1-rb);
        area = (area < tmp ? tmp : area);
        if (j < col && '0' == matrix[i][j]) {
            col = j;
        }
    }
    return area;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    int i, j, tmp, area = 0;
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == '0') {
                continue;
            }
            tmp = max_rect(matrix, i, j, matrixSize, matrixColSize[i]);
            area = (area < tmp ? tmp : area);
        }
    }
    return area;
}

int main(int argc, char *argv[]) {
    char array[][5] = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    char *pp[] = {array[0], array[1], array[2], array[3]};
    int cols[] = {5, 5, 5, 5, 5};
    print_array(pp, 4, 5);
    printf("%d\n", maximalRectangle(pp, 4, cols));
    return 0;
}

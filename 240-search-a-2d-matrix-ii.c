#include <stdio.h>

/* lower bound */
int row_bound(int** matrix, int size, int col, int target){
    int mid, low, high;
    low = 0;
    high = size - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (matrix[mid][col] == target) {
            return mid;
        } else if (matrix[mid][col] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int bin_search(int *nums, int size, int target) {
    int mid, low, high;
    low  = 0;
    high = size - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[mid] < target) {
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i, begin, end, last;
    /* locate row */
    last  = matrixColSize[0] - 1; /* 行的最后一个下标 */
    begin = row_bound(matrix, matrixSize, last, target);
    end   = row_bound(matrix, matrixSize, 0, target);
    for (i = begin; i < matrixSize && i <= end; i++) {
        if (bin_search(matrix[i], last+1, target) > -1) {
            return true;
        }
    }
    return false;
}

int
main(int argc, char *argv[]){
    int array[][5] = {{7}};
    int *pp[] = {array[0]};
    int cols[] = {1};
    bool r = searchMatrix(pp, sizeof(pp)/sizeof(pp[0]), cols, 7);
    if (r) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}

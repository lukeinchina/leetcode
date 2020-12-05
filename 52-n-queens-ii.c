#include <stdio.h>
#include <stdlib.h>
#define INVALID -1
#define abs(a) ((a) > 0 ? (a) : -(a))

void make_empty(int *queen, int size) {
    int i;
    for (i = 0; i < size; i++) {
        queen[i] = INVALID;
    }
}

int can_place(int *queen, int size, int row, int col) {
    int i;
    for (i = 0; i < size; i++) {
        if (queen[i] != INVALID && (i == row || col == queen[i]
                    || abs(i-row) == abs(queen[i]-col))) {
            return 0;
        }
    }
    return 1;
}

int place_queen(int row, int *queen, int size, int *count) {
    int i;
    if (row == size) {
        *count += 1;
        return 1;
    }
    for (i = 0; i < size; i++) {
        if (can_place(queen, size, row, i)) {
            queen[row] = i;
            place_queen(row+1, queen, size, count);
            queen[row] = INVALID;
        }
    }
    return 0;
}

int totalNQueens(int n){
    int *queen = (int *)malloc(sizeof(int) * n);
    make_empty(queen, n);
    int count = 0;
    place_queen(0, queen, n, &count);
    free(queen);
    return count;
}


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

#define INVALID -1
#define abs(a) ((a) > 0 ? (a) : -(a))

void make_empty(int *queen, int size) {
    int i;
    for (i = 0; i < size; i++) {
        queen[i] = INVALID;
    }
}

void print_chessboard(char **board, int size) {
    int i,j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("-------------\n");
}

void print_queen(int *queen, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (queen[i] == j) {
                printf("Q");
            }else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void solution_append(int *queen, int size, vector<vector<string> > &rst) {
    int i, j;
    vector<string> one;
    for (i = 0; i < size; i++) {
        string s;
        for (j = 0; j < size; j++) {
            if (queen[i] == j) {
                s.push_back('Q');
            }else {
                s.push_back('.');
            }
        }
        one.push_back(s);
    }
    rst.push_back(one);
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

int place_queen(int row, int *queen, int size, vector<vector<string> > &rst) {
    int i;
    if (row == size) {
        solution_append(queen, size, rst);
        print_queen(queen, size);
        return 0;
    }
    for (i = 0; i < size; i++) {
        if (can_place(queen, size, row, i)) {
            queen[row] = i;
            place_queen(row+1, queen, size, rst);
            queen[row] = INVALID;
        }
    }
    return 0;
}

vector<vector<string> > solveNQueens(int n) {
    vector< vector<string> > rst;
    int *queen = (int *)malloc(sizeof(int) * n);
    make_empty(queen, n);
    place_queen(0, queen, n, rst);
    free(queen);
    return rst;
}

int
main(void) {
    int size = 0;
    int *cols;
    solveNQueens(4);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int i, j, m, n;
    char c;
    int flags[10] = {0};
    for (i = 0; i < boardSize; i++) {
        memset(flags, 0, sizeof(flags));
        for (j = 0; j < boardColSize[i]; j++) {
            c = board[i][j];
            if (c == '.') {
                continue;
            }
            if (flags[c-'0']) {
                return false;
            }
            flags[c-'0'] = 1;
        }
    }
    for (i = 0; i < boardSize; i++) {
        memset(flags, 0, sizeof(flags));
        for (j = 0; j < boardColSize[i]; j++) {
            c = board[j][i];
            if (c == '.') {
                continue;
            }
            if (flags[c-'0']) {
                return false;
            }
            flags[c-'0'] = 1;
        }
    }
    for (m = 0; m < boardSize; m += 3){
        for (n = 0; n < boardSize; n += 3) {
            memset(flags, 0, sizeof(flags));
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    c = board[m+i][n+j];
                    if (c == '.') {
                        continue;
                    }
                    if (flags[c-'0']) {
                        return false;
                    }
                    flags[c-'0'] = 1;
                }
            }
        }
    }
    return true;
}

int
main(void) {
    char case1[9][9] = {
          {'5','3','.','.','7','.','.','.','.'},
          {'6','.','.','1','9','5','.','.','.'},
          {'.','9','8','.','.','.','.','6','.'},
          {'8','.','.','.','6','.','.','.','3'},
          {'4','.','.','8','.','3','.','.','1'},
          {'7','.','.','.','2','.','.','.','6'},
          {'.','6','.','.','.','.','2','8','.'},
          {'.','.','.','4','1','9','.','.','5'},
          {'.','.','.','.','8','.','.','7','9'}
    };
    char case2[9][9] = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    char *test1[9];
    char *test2[9]; 
    int  cols[9] = {9,9,9,9,9,9,9,9,9};
    int i;
    for (i = 0; i < 9; i++) {
        test1[i] = case1[i];
        test2[i] = case2[i];
    }
    printf("%d\n",  isValidSudoku(test1, 9, cols));
    printf("%d\n",  isValidSudoku(test2, 9, cols));
}

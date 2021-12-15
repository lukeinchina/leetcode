#include <stdio.h>
#include <stdlib.h>

void print_board(const char **board, int row, int col);

int get_avbl(char **board, int size, int row, int col, char *digits) {
    int i, j, n = 0;
    for (i = 0; i < size; i++) {
        if (board[row][i] != '.') {
            digits[board[row][i] - '1'] = '0';
        }
        if (board[i][col] != '.') {
            digits[board[i][col] - '1'] = '0';
        }
    }
    row = row / 3 * 3;
    col = col / 3 * 3;
    for (i = row; i < row+3; i++) {
        for (j = col; j < col+3; j++) {
            if (board[i][j] != '.') {
                digits[board[i][j] - '1'] = '0';
            }
        }
    }
    for (i = 0; i < 9; i++) {
        if (digits[i] != '0') {
            digits[n++] = digits[i];
        }
    }
    return n;
}

int get_task(char **board, int size, int rows[], int cols[]) {
    int i, j, n = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (board[i][j] != '.') {
                continue;
            }
            rows[n] = i;
            cols[n] = j;
            n++;
        }
    }
    return n;
}

int backtrack(char **board, int size, int rows[], int cols[], int n) {
    int i, count;
    char digits[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    if (n == 0) {
        printf("-------------------\n");
        print_board(board, size, size);
        printf("-------------------\n");
        return 1;
    }
    count = get_avbl(board, size, rows[n-1], cols[n-1], digits);
    for (i = 0; i < count; i++) {
        board[rows[n-1]][cols[n-1]] = digits[i];
        if (backtrack(board, size, rows, cols, n-1)) {
            return 1;
        }
        board[rows[n-1]][cols[n-1]] = '.';
    }
    return 0;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    int *rows = (int *)malloc(sizeof(int) * boardSize * boardSize);
    int *cols = (int *)malloc(sizeof(int) * boardSize * boardSize);
    int n = get_task(board, boardSize, rows, cols);
    backtrack(board, boardSize, rows, cols, n);
    free(rows);
    free(cols);
    return ;
}

void print_board(const char **board, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%c%c", board[i][j], j+1 == col ? '\n' : ' ');
        }
    }
}

int
main(void) {
    char board[9][9] = {
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
    char solution[9][9] = {
        {'5','3','4','6','7','8','9','1','2'},
        {'6','7','2','1','9','5','3','4','8'},
        {'1','9','8','3','4','2','5','6','7'},
        {'8','5','9','7','6','1','4','2','3'},
        {'4','2','6','8','5','3','7','9','1'},
        {'7','1','3','9','2','4','8','5','6'},
        {'9','6','1','5','3','7','2','8','4'},
        {'2','8','7','4','1','9','6','3','5'},
        {'3','4','5','2','8','6','1','7','9'}
    };

    char *ptrs[9] = {board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]};
    char *pp[9] = {solution[0], solution[1], solution[2], solution[3], 
        solution[4], solution[5], solution[6], solution[7], solution[8]};
    int cols[9] = {9};
    print_board(ptrs, 9, 9);
    printf("\n");
    solveSudoku(ptrs, 9, cols);
    print_board(pp, 9, 9);
    return 0;
}

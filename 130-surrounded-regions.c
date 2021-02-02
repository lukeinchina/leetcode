#include <stdio.h>


void print_matrix(char **board, int n, int m) {
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%c%c", board[i][j], j+1==m ? '\n': ' ');
        }
    }
}

void dfs(char **board, int row, int col, int i, int j) {
    if (i >= row || j >= col || i < 0 || j < 0 || 'O' != board[i][j]) {
        return;
    }
    board[i][j] = 'A';
    dfs(board, row, col, i-1, j);
    dfs(board, row, col, i, j+1);
    dfs(board, row, col, i+1, j);
    dfs(board, row, col, i, j-1);
}

void solve(char** board, int boardSize, int* boardColSize){
    int i, j, row, col;
    row = boardSize;
    col = (boardSize > 0 ? boardColSize[0] : 0);

    for (i = 0; i < col; i++) {
        if ('O' == board[0][i]) {
            dfs(board, row, col, 0, i);
        }
        if ('O' == board[row-1][i]) {
            dfs(board, row, col, row-1, i);
        }
    }
    for (i = 1; i < row-1; i++) {
        if ('O' == board[i][0]) {
            dfs(board, row, col, i, 0);
        }
        if ('O' == board[i][col-1]) {
            dfs(board, row, col, i, col-1);
        }
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if ('O' == board[i][j]) {
                board[i][j] = 'X';
            } else if ('A' == board[i][j]) {
                board[i][j] = 'O';
            }
        }
    }
}

int
main(void) {
    char matrix[][4] = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'}, 
        {'X', 'X', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}};
    char *board[] = {matrix[0], matrix[1], matrix[2], matrix[3]};
    int cols[] = {4, 4, 4, 4};
    print_matrix(board, 4, 4);
    solve(board, 4, cols);
    printf("---------\n");
    print_matrix(board, 4, 4);
    return 0;
}

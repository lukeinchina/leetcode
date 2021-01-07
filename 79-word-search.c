#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Cord {
    int r;
    int c;
};

int dfs(char** board, int **visited, int row, int col, int i, int j, char *word){
    int n;
    struct Cord a[4] = {{i-1, j}, {i, j+1}, {i+1, j}, {i, j-1}};
    if ('\0' == *word) {
        return 1;
    }
    for (n = 0; n < 4; n++) {
        if (a[n].r >= 0 && a[n].r < row && a[n].c >= 0 && a[n].c < col
                && !visited[a[n].r][a[n].c] && *word == board[a[n].r][a[n].c]) {
            visited[a[n].r][a[n].c] = 1;
            if (dfs(board, visited, row, col, a[n].r, a[n].c, word+1)) {
                return 1;
            }
            visited[a[n].r][a[n].c] = 0;
        }
    }
    return 0;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int i, j, row, col;
    bool find = false;
    int **visited;
    row = boardSize;
    col = boardColSize[0];
    visited = (int **)malloc(sizeof(int *) * row);
    for (i = 0; i < row; i++) {
        visited[i] = (int *)malloc(sizeof(int) * col);
        for (j = 0; j < col; j++)  {
            visited[i][i] = 0;
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (*word != board[i][j]) {
                continue;
            }
            visited[i][j] = 1;
            find = dfs(board, visited, row, col, i, j, word+1);
            if (find) {
                goto finished;
            }
            visited[i][j] = 0;
        }
    }

finished:
    for (i = 0; i < row; i++) {
        free(visited[i]);
    }
    free(visited);
    return find;
}

void print_array(char **matrix, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%c %c", matrix[i][j], j+1 == col ? '\n' : ' ');
        }
    }
    printf("-----------------\n");
}

int main(int argc, char *argv[]) {
    char array[][4] = {{'A','B','C','E'},  {'S','F','C','S'}, {'A','D','E','E'}};
    char *pp[] = {array[0], array[1], array[2]};
    int cols[] = {4, 4, 4};
    if (argc < 2) {
        printf("usage:%s string \n", argv[0]);
        return -1;
    }
    print_array(pp, 3, 4);
    printf("%d\n", exist(pp, 3, cols, argv[1]));
    return 0;
}

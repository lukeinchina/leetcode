#include <stdio.h>
#include <stdlib.h>

#define INVALID -1
#define abs(a) ((a) > 0 ? (a) : -(a))

struct ChessBoard {
    char **board;
    int  width;  /* width * width */
};
struct NQueenSolution {
    struct ChessBoard *array;
    int size;
    int capacity;
};

struct ChessBoard 
create_chessboard(int *queen, int size) {
    int i,j;
    struct ChessBoard one = {NULL, size};
    char **board = (char **)malloc(sizeof(char *) * size);
    for (i = 0; i < size; i++) {
        board[i] = (char *)malloc(sizeof(char) * size);
        for (j = 0; j < size; j++) {
            if (queen[i] == j) {
                board[i][j] = 'Q';
            }else {
                board[i][j] = '.';
            }
        }
    }
    one.board = board;
    return  one;
}

int solution_append(struct NQueenSolution *head, int *queen, int size) {
    if(head->capacity <= 0) {
        head->capacity = 2;
        head->size     = 0;
        head->array    = (struct ChessBoard *)malloc(
                            sizeof(struct ChessBoard) * head->capacity);
    } else if (head->size == head->capacity) {
        head->capacity *= 2;
        head->array = (struct ChessBoard *)realloc(head->array, 
                        sizeof(struct ChessBoard) * head->capacity);
    }
    head->array[head->size++] = create_chessboard(queen, size);
    return 0;
}

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

int place_queen(int row, int *queen, int size, struct NQueenSolution *head) {
    int i;
    if (row == size) {
        solution_append(head, queen, size);        
        return 0;
    }
    for (i = 0; i < size; i++) {
        if (can_place(queen, size, row, i)) {
            queen[row] = i;
            place_queen(row+1, queen, size, head);
            queen[row] = INVALID;
        }
    }
    return 0;
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    int i;
    char ***result = NULL;
    int *cols = NULL;
    int *queen = (int *)malloc(sizeof(int) * n);
    struct NQueenSolution head = {NULL, 0, 0};

    make_empty(queen, n);
    place_queen(0, queen, n, &head);
    *returnSize = 0;
    if (head.size > 0) {
        *returnSize = head.size;
        result = (char ***)malloc(sizeof(char **) * head.size);
        cols   = (int *)malloc(sizeof(int) * head.size);
        for (i = 0; i < head.size; i++) {
            result[i] = head.array[i].board;
            cols[i]   = head.array[i].width;
        }
        *returnColumnSizes = cols;
        free(head.array);
    }
    free(queen);
    return result;
}

int
main(void) {
    int size = 0;
    int *cols;
    solveNQueens(5, &size, &cols);
}

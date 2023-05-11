#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ResultHead {
    char **strs;
    int size;
    int capacity;
};

void append_result(const char *str, struct ResultHead *head) {
    if (head->capacity == 0) {
        head->capacity = 2;
        head->strs = (char **)malloc(sizeof(char *) * head->capacity);
    } else if (head->size == head->capacity) {
        head->capacity <<= 1;
        head->strs = (char **)realloc(head->strs, sizeof(char *) * head->capacity);
    }
    head->strs[head->size] = strdup(str);
    head->size += 1;
    return ;
}

int dfs(char **board, int size, int row, int col, const char *word) {
    return 0;
}

int match_word(char** board, int size, const char *word) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (dfs(board, size, i, j, word)) {
                return 1;
            }
        }
    }
    return 0;
}

char ** findWords(char** board, int boardSize, int* boardColSize, 
        char ** words, int wordsSize, int* returnSize){
    struct ResultHead head = {NULL, 0, 0};
    int i;
    for (i = 0; i < wordsSize; i++) {
        if (match_word(board, boardSize, words[i])) {
            append_result(words[i], &head);
        }
    }
    *returnSize = head.size;
    return head.strs;
}

int
main(void) {
    char *board[] = {"oaan", "etae", "ihkr", "iflv"};
    char *words[]  = {"oath","pea","eat","rain"};
    int cols[] = {4,4,4,4};
    int i, size = 0;
    char **strs = findWords(board, sizeof(board) / sizeof(board[0]), 
            cols, words, sizeof(words) / sizeof(words[0]), &size);
    printf("count : %d\n", size);
    for (i = 0; i < size; i++) {
        printf("%s%c", strs[i], i+1 == size ? '\n' : '\t');
        free(strs[i]);
    }
    free(strs);
    return 0;
}

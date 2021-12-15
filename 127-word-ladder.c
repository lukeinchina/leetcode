#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>

#include "common/queue.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct AdjTable {
    struct ListNode *table;
    int size;
};

int diff(const char *s, const char *t) {
    int d = 0;
    while ('\0' != *s && '\0' != *t) {
        d += (*s++ != *t++);
    }
    return d;
}

void print_path(char **words, int size, int *stack, int top) {
    for (; top > 0; top--) {
        printf("[%s]%c", words[stack[top-1]], top==1? '\n' : '-');
    }
}


void adj_table_init(struct AdjTable *head, int size) {
    head->size  = size;
    head->table = (struct ListNode *)calloc(size, sizeof(struct ListNode));
    return ;
}

void adj_table_destroy(struct AdjTable *head) {
    int i;
    struct ListNode *p;
    for (i = 0; i < head->size; i++) {
        for (p = head->table[i].next; NULL != p; p = head->table[i].next) {
            head->table[i].next = p->next;
            free(p);
        }
    }
    free(head->table);

    head->table = NULL;
    head->size  = 0;
}

int 
adj_table_add(struct AdjTable *head, int begin, int end) {
    struct ListNode *p      = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->val                  = end;
    p->next                 = head->table[begin].next;
    head->table[begin].next = p;
    return 0;
}

void dfs(struct AdjTable *head, int v, int end, 
        int visited[], int stack[], int top, int *min) {
    int i;
    struct ListNode *p = NULL;
    if (top >= *min) {
        return ;
    }
    visited[v]   = 1;
    stack[top++] = v;
    if (end == v) {
        stack[top] = v;
        *min = (top < *min ? top : *min);
        for (i = 0; i < top; i++) {
            printf("%d%c", stack[i], i+1 == top ? '\n' : '-');
        }
        return;
    }
    for (p = head->table[v].next; NULL != p; p = p->next) {
        if (visited[p->val]) {
            continue;
        }
        dfs(head, p->val, end, visited, stack, top, min);
    }
    visited[v] = 0;
}

int **
create_matrix(int row, int col) {
    int i;
    int **matrix = (int **)malloc(sizeof(int *) * row);
    for (i = 0; i < row; i++) {
        matrix[i] = (int *)calloc(col, sizeof(int));
    }
    return matrix;
}

void *
destory_matrix(int **matrix, int row) {
    int i = 0;
    for (i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return NULL;
}

int bfs(int **matrix, int size, int begin, int end) {
    int min = 1 << 16;
    int i, v, level = 0;
    int *visited = (int *)calloc(size, sizeof(int));
    struct Queue *queue = create_queue();
    struct Queue *next  = create_queue();
    struct Queue *temp  = NULL;

    queue_push(queue, begin);
    visited[begin] = 1;

    while (!queue_empty(queue)) {
        level++;
        while (!queue_empty(queue)) {
            queue_pop(queue, &v);
            if (v == end) {
                min = level;
                goto EXIT;
            }
            for (i = 0; i < size; i++) {
                if (matrix[v][i] && !visited[i]) {
                    queue_push(next, i);
                    visited[i] = 1;
                }
            }
        }
        temp  = queue;
        queue = next;
        next  = temp;
    }
EXIT:
    queue = free_queue(queue);
    next  = free_queue(next);
    free(visited);
    return (min < (1<<16) ? min : 0);
}

/*-----------------------------------------------------------------*/
int ladderLength(char * beginWord, char * endWord, char ** wordList, 
        int wordListSize){
    int i, j, begin, end, min;
    int **matrix = create_matrix(wordListSize+1, wordListSize+1);
    end     = -1; 
    begin   = wordListSize;

    for (i = 0; i < wordListSize; i++) {
        if (0 == strcmp(beginWord, wordList[i])) {
            begin = i;
        }
        if (0 == strcmp(wordList[i], endWord)) {
            end = i;
        }
        for (j = i+1; j < wordListSize; j++) {
            if (1 != diff(wordList[i], wordList[j])) {
                continue;
            }
            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }
    }

    if (wordListSize == begin) {
        for (i = 0; i < wordListSize; i++) {
            if (1 != diff(beginWord, wordList[i])) {
                continue;
            }
            matrix[begin][i] = 1;
            matrix[i][begin] = 1;

        }
    }
    min = bfs(matrix, wordListSize+1, begin, end);
    destory_matrix(matrix, wordListSize+1);
    return min;
}

/* ------------------------------------------------------------*/
int get_line_count(const char *path) {
    char line[1024];
    int count = 0;
    FILE *fp = fopen(path, "r");
    while (NULL != fgets(line, sizeof(line), fp)) {
        count += 1;
    }
    fclose(fp);
    return count;
}

char **
read_test_case(const char *path, int *count) {
    char **pp = NULL; 
    char line[256];
    FILE *fp = NULL;
    int i = 0;
    int len;
    *count = get_line_count(path);
    if (*count <= 0) {
        return NULL;
    }
    pp = (char **)malloc(sizeof(char *) * *count);
    fp = fopen(path, "r");
    while (NULL != fgets(line, sizeof(line), fp)) {
        len = strlen(line);
        while (isspace(line[len-1])) {
            line[--len] = '\0';
        }
        pp[i++] = strdup(line);
    }
    fclose(fp);
    return pp;
}

int
main(int argc, char *argv[]) {
    int size = 0;
    char **strs = read_test_case("./case.txt", &size);
    // char *strs[] = {"hot","dot","dog","lot","log","cog"};
    if (argc < 3) {
        printf("usage:%s begin  end\n", argv[0]);
        return -1;
    }

    printf("input count:%d\n", size);
    // printf("min path: %d\n", ladderLength(argv[1], argv[2], strs, sizeof(strs)/sizeof(strs[0])));
    printf("min path: %d\n", ladderLength(argv[1], argv[2], strs, size));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

/*---------------------原始版本DFS --------------------------*/
int find(char **words, int size, const char *word) {
    int i;
    for (i = 0; i < size; i++) {
        if (0 == strcmp(words[i], word)) {
            return i;
        }
    }
    return -1;
}

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

int dfs(const char *begin, const char *end, 
        char **words, int size,
        int *visited, int *stack, int top, int *max) {
    int i, d;
    /* 剪枝 */
    if (top >= *max) {
        return 0;
    }
    if ((d = diff(begin, end)) == 1) {
        print_path(words, size, stack, top);
        top += 1;
        *max = (*max > top ? top : *max);
        return 0;
    }
    for (i = 0; i < size; i++) {
        if (visited[i]) {
            continue;
        }
        d = diff(begin, words[i]);
        if (d < 2) {
            visited[i] = 1;
            stack[top] = i;
            dfs(words[i], end, words, size, visited, stack, top+1, max);
            visited[i] = 0;
        }
    }
    return 0;
}
/*------------------------优化版----------------------------------*/

struct AdjTable {
    int **table;
    int *cols;
    int size;
};

void adj_table_init(struct AdjTable *head, int size) {
    head->size  = size;
    head->cols  = (int *)calloc(size, sizeof(int));
    head->table = (int **)calloc(size, sizeof(int *));
    return ;
}

void adj_table_destroy(struct AdjTable *head) {
    int i;
    for (i = 0; i < head->size; i++) {
        if (NULL != head->table[i]) {
            free(head->table[i]);
        }
    }
    free(head->cols);

    head->table = NULL;
    head->cols  = NULL;
    head->size  = 0;
}

int 
adj_table_add(struct AdjTable *head, int begin, int *ends, int size) {
    assert(begin < head->size);
    assert(NULL == head->table[begin]);

    head->table[begin] = (int *)malloc(size * sizeof(*ends));
    memcpy(head->table[begin], ends, sizeof(*ends) * size);
    head->cols[begin] = size;
    return 0;
}

/*-----------------------------------------------------------------*/
int ladderLength(char * beginWord, char * endWord, char ** wordList, 
        int wordListSize){
    int pos, distance = 65536;
    int *visited, *stack;

    /* 目标不在，直接返回 */
    if ((pos = find(wordList, wordListSize, endWord)) < 0) {
        return 0;
    }
    visited = (int *)calloc(wordListSize, sizeof(int));
    stack   = (int *)calloc(wordListSize, sizeof(int));
    // visited[pos] = 1;
    stack[0]     = pos;
    dfs(beginWord, endWord, wordList, wordListSize, visited, stack, 0, &distance);
    free(visited);
    free(stack);
    return (distance < 65536 ? distance+1 : 0);
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
//    char **strs = read_test_case("./case.txt", &size);
    char *strs[] = {"hot","dot","dog","lot","log","cog"};
    if (argc < 3) {
        printf("usage:%s begin  end\n", argv[0]);
        return -1;
    }

    printf("input count:%d\n", size);
    printf("min path: %d\n", ladderLength(argv[1], argv[2], strs, sizeof(strs)/sizeof(strs[0])));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct WordDict {
    char **words;
    int  *lens;
    int   count;
};

struct BreakWords {
    char **words;
    int count;
    int size;
};

void result_init(struct BreakWords *head) {
    head->size  = 2;
    head->count = 0;
    head->words = (char **)malloc(sizeof(char *) * head->size);
}

struct WordDict *
create_dict(struct WordDict *dict, char **words, int word_count) {
    int i;
    dict->words = words;
    dict->lens  = (int *)malloc(sizeof(int) * word_count);
    dict->count = word_count;
    for (i = 0; i < word_count; i++) {
        dict->lens[i] = strlen(words[i]);
    }
    return dict;
}

struct WordDict *
destroy_dict(struct WordDict *dict) {
    free(dict->lens);
    dict->words = NULL;
    dict->lens  = NULL;
    dict->count = 0;
    return dict;
}

void result_append(char *word, struct BreakWords *rst) {
    if (rst->size == 0) {
        result_init(rst);
    }
    if (rst->count == rst->size) {
        rst->size *= 2;
        rst->words = (char **)realloc(rst->words, sizeof(char *) * rst->size);
    }
    rst->words[rst->count++] = word;
}

void create_solution(const struct WordDict *dict, 
        int stack[], int top, struct BreakWords *rst) {
    int i, offset, size = 1;
    char *word  = NULL;

    /* 计算需要空间 */
    for (i = 0; i < top; i++) {
        size += dict->lens[stack[i]];
        size += (i > 0 ? 1 : 0);
    }

    /* 拼装成单词字符串 */
    offset = 0;
    word   = (char *)malloc(sizeof(char) * size);
    for (i = 0; i < top; i++) {
        if (i > 0) {
            word[offset++] = ' ';
        }
        memcpy(word+offset, dict->words[stack[i]], dict->lens[stack[i]]);
        offset += dict->lens[stack[i]];
    }
    word[offset] = '\0';

    /* 放入结果集返回 */
    result_append(word, rst);
}

int dfs(const char *str, const struct WordDict *dict, 
        int stack[], int top, struct BreakWords *rst) {
    int i;
    if ('\0' == *str) {
        create_solution(dict, stack, top, rst);
        return 1;
    }
    for (i = 0; i < dict->count; i++) {
        if (0 != strncmp(dict->words[i], str, dict->lens[i])) {
            continue;
        }
        stack[top] = i;
        dfs(str + dict->lens[i], dict, stack, top+1, rst);
    }
    return 0;
}


char ** 
wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize){
    int len, *stack ;
    struct WordDict   dict = {NULL, NULL, 0};
    struct BreakWords rst  = {NULL, 0, 0};
    len     = strlen(s);
    stack   = (int *)calloc(len, sizeof(int));
    create_dict(&dict, wordDict, wordDictSize);
    dfs(s, &dict, stack, 0, &rst);

    destroy_dict(&dict);
    *returnSize = rst.count;
    return rst.words;
}


int
main(int argc, char *argv[]) {
    char **pp = NULL;
    int i, size = 0;
    if (argc < 3) {
        printf("usage:%s str str1 str2...\n", argv[0]);
        return -1;
    }
    pp =  wordBreak(argv[1], argv+2, argc-2, &size);
    for (i = 0; i < size; i++) {
        printf("[%s]\n", pp[i]);
    }
    return 0;
}

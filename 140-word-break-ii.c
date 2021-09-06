#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*------------------------ result store ---------------------------*/
struct RstHead {
    char **pp;
    int size;
    int capacity;
};

void result_init(struct RstHead *head) {
    head->capacity = 2;
    head->size     = 0;
    head->pp       = (char **)malloc(sizeof(char *) * head->capacity);
}

void result_append(char **words, int size, int *lens, int *stack, int top, 
        struct RstHead *head) {
    int i, offset, total = 1;
    char *p   = NULL;
    if (0 == head->capacity) {
        result_init(head);
    } else if (head->size == head->capacity) {
        head->capacity *= 2;
        head->pp = (char **)realloc(head->pp, sizeof(char *) * head->capacity);
    }

    /* 计算需要buffer size */
    total = 1; /* 存储结束字符 */
    for (i = 0; i < top; i++) {
        assert(stack[i] < size);
        total += lens[stack[i]];
    }
    total += (top - 1); /* 需要空格数目 */

    /* 拼装最终字符串 */
    p = (char *)malloc(total);
    for (offset = i = 0; i < top; i++) {
        strncpy(p+offset, words[stack[i]], lens[stack[i]]);
        offset += lens[stack[i]];
        p[offset] = ' ';
        offset += (i+1 == top) ? 0 : 1;
    }
    p[offset] = '\0';

    head->pp[head->size] = p;
    head->size += 1;

}
/*------------------------ result store ---------------------------*/

/*-------------------------- tire -------------------------*/
#define SIZE 26
struct TireNode {
    char   c;
    char   fin;
    int    id;
    struct TireNode *nexts[SIZE];
};

int
tire_insert(struct TireNode *root, const char *str) {
    static int id = 0;

    for (; '\0' != *str; str++) {
        if (NULL == root->nexts[*str - 'a']) {
            root->nexts[*str - 'a'] = (struct TireNode *)calloc(1, sizeof(struct TireNode));
        }
        root    = root->nexts[*str - 'a'];
        root->c = *str;
    }
    root->fin = 1; 
    root->id  = id++; /* 按顺序自动生成单词id */
    return 1;
}

struct TireNode *
tire_create(void) {
    return (struct TireNode *)calloc(1, sizeof(struct TireNode));
}

struct TireNode *
tire_free(struct TireNode *root) {
    int i;
    if (NULL == root) {
        return NULL;
    }
    for (i = 0; i < SIZE; i++) {
        if (NULL != root->nexts[i]) {
            root->nexts[i] = tire_free(root->nexts[i]);
        }
    }
    free(root);
    return NULL;
}

/*
 *@brief:匹配到tire tire中可能存在的单词。
 *       返回匹配到单词的数目，匹配到的单词的存在matches返回。
 */
int tire_match(const struct TireNode *root, const char *str,
        int *matches) {
    int count     = 0;
    for (; '\0' != *str; str++) {
        if (NULL == (root = root->nexts[*str - 'a'])) {
            break;
        }

        /* 匹配到一个word */
        if (root->fin) {
            matches[count++] = root->id;
        }
    }
    return count;
}

int 
tire_has(const struct TireNode *root, const char *str) {
     for (; '\0' != *str; str++) {
        if (NULL == (root = root->nexts[*str - 'a'])) {
            break;
        }
    }
    /* 匹配到一个word */
    return ('\0' == *str && root->fin);
}
/*------------------------ tire ---------------------------*/

void print_stack(char **words, int size, int *stack, int top) {
    int i = 0;
    printf("[");
    for (i = 0; i < top; i++) {
        printf("%s ", words[stack[i]]);
    }
    printf("]\n");
}

void dfs(char *s, char **words, int size, 
        int *lens, int *matches, struct TireNode *root,
        int *stack, int top, struct RstHead *head) {
    int i, n;
    if ('\0' == *s) {
        // print_stack(words, size, stack, top);
        result_append(words, size, lens, stack, top, head);
        return;
    }
    n = tire_match(root, s, matches);
    for (i = n; i > 0; i--) {
        stack[top] = matches[i-1];
        dfs(s+lens[matches[i-1]], words, size, lens, matches+n, root, stack, top+1, head);
    } 
}

char ** 
wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize){
    int i, len, *stack, *matches, *lens;
    struct TireNode *root;

    struct RstHead head = {NULL, 0, 0};

    len     = strlen(s);
    matches = (int *)calloc(len * wordDictSize, sizeof(int));
    stack   = (int *)calloc(len, sizeof(int));
    lens    = (int *)calloc(wordDictSize, sizeof(int));

    /* 构建tire tree */
    root = tire_create();
    for (i = 0; i < wordDictSize; i++) {
        tire_insert(root, wordDict[i]);
        /* 兼职 */
        lens[i] = strlen(wordDict[i]);
    }

    /* 开始干活 */
    dfs(s, wordDict, wordDictSize, lens, matches, root, stack, 0, &head);

    root = tire_free(root);
    free(matches);
    free(stack);
    free(lens);

    *returnSize = head.size;
    return head.pp;
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
    printf("[");
    for (i = 0; i < size; i++) {
        printf("\n%s\n", pp[i]);
    }
    printf("]\n");
    return 0;
}

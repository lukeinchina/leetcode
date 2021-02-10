#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26
struct TireNode {
    char   c;
    char   fin;
    struct TireNode *nexts[SIZE];
};

int
tire_insert(struct TireNode *root, const char *str) {
    for (; '\0' != *str; str++) {
        if (NULL == root->nexts[*str - 'a']) {
            root->nexts[*str - 'a'] = (struct TireNode *)calloc(1, sizeof(struct TireNode));
        }
        root    = root->nexts[*str - 'a'];
        root->c = *str;
    }
    root->fin = 1; 
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

int tire_match(const struct TireNode *root, const char *str) {
    int count     = 0;
    int match_len = 0;
    for (; '\0' != *str; str++) {
        if (NULL == (root = root->nexts[*str - 'a'])) {
            break;
        }

        count++; 
        /* 匹配到一个word */
        match_len = root->fin ? count : match_len;
    }
    return match_len;
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

bool wordBreak1(char * s, char ** wordDict, int wordDictSize){
    int i, len;
    struct TireNode *root = tire_create();
    for (i = 0; i < wordDictSize; i++) {
        tire_insert(root, wordDict[i]);
    }
    while ('\0' != *s) {
        len = tire_match(root, s);
        if (len <= 0) {
            break;
        }
        s += len;
    }
    root = tire_free(root);
    return ('\0' == *s);
}

int 
str_begin_with(const char *s, const char *t) {
    int len = 0;
    while ('\0' != *s && '\0' != *t && *s++ == *t++) {
        len++;
    }
    return ('\0' == *t ? len : 0);
}

bool wordBreak2(char * s, char ** wordDict, int wordDictSize){
    int i, len;
    if ('\0' == *s) {
        return true;
    }
    for (i = 0; i < wordDictSize; i++) {
        len = str_begin_with(s, wordDict[i]);
        if (len > 0 && wordBreak2(s+len, wordDict, wordDictSize)) {
            return true;
        }
    }
    return  false;
}

bool wordBreak3(char * s, char ** wordDict, int wordDictSize){
    int i, j, len, res, c, max_item, *dp;
    struct TireNode *root = NULL;

    root = tire_create();
    for (max_item = i = 0; i < wordDictSize; i++) {
        tire_insert(root, wordDict[i]);

        /* 兼职 */
        len      = strlen(wordDict[i]);
        max_item = (len > max_item ? len : max_item);
    }

    len  = strlen(s);
    dp   = (int *)calloc(len+1, sizeof(int));
    for (dp[0] = i = 1; i <= len; i++) {
        c    = s[i];
        s[i] = '\0';
        for (j = 0; j < i && j < max_item; j++) {
            if (dp[i-j-1] && tire_has(root, s+i-j-1)) {
                dp[i] = 1;
                break;
            }
        }
        s[i] = c;
    }
    res = dp[len];
    free(dp);
    root = tire_free(root);
    return  res;
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage:%s str str1 str2...\n", argv[0]);
        return -1;
    }
    printf("%d\n", wordBreak3(argv[1], argv+2, argc-2));
    return 0;
}

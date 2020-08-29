#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "common/vector.h"

const static int ALPHABET_SIZE = 26;
struct TireNode {
    int id;
    struct TireNode *children[ALPHABET_SIZE];
};

/* */
int tire_tree_insert(struct TireNode *root, const char *word) {
    static int s_auto_id = 0;
    int exist = 1;
    for (; '\0' != *word; word++) {
        if (NULL == root->children[*word-'a']) {
            root->children[*word - 'a'] = (struct TireNode *)calloc(1, sizeof(struct TireNode));
            exist = 0;
        }
        root = root->children[*word - 'a'];
    }
    if (!exist) {
        root->id = s_auto_id++;
    }
    return root->id;
}

/* 返回匹配上id */
int tire_tree_search(const struct TireNode *root, const char *str, int search_len) {
    int i = 0;
    for (; i < search_len && NULL != root->children[*(str+i) - 'a']; i++) {
        root = root->children[*(str+i) - 'a'];
    }
    return (i == search_len ? root->id : -1);
}

struct TireNode *trie_tree_destroy(struct TireNode *root) {
    int i = 0;
    if (NULL == root) {
        return NULL;
    }

    for (; i < ALPHABET_SIZE; i++) {
        if (NULL != root->children[i]) {
            root->children[i] = trie_tree_destroy(root->children[i]);
        }
    }
    free(root);
    return NULL;
}

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    int i, id;
    struct Vector dst = {NULL, 0, 0};
    int wordlen       = strlen(words[0]);
    int batchlen      = wordlen * wordsSize;
    const char *end   = s + strlen(s);
    const char *p     = s;
    struct TireNode *root = (struct TireNode *)calloc(1, sizeof(struct TireNode));
    int *dup   = (int *)calloc(wordsSize, sizeof(int));
    int *matched = (int *)calloc(wordsSize, sizeof(int));
    for (i = 0; i < wordsSize; i++) {
        id = tire_tree_insert(root, words[i]);
        dup[id] += 1;
    }

    while(p + batchlen < end) {
        memset(matched, 0, sizeof(int) * wordsSize);
        for (i = 0; i < wordsSize; i++) {
            id = tire_tree_search(root, p+i*wordlen, wordlen);
            if (id < 0) {
                break;
            }
            matched[id] += 1;
        }
        if (i < wordsSize) {
            p++;
            continue;
        } 
        for (i = 0; i < wordsSize; i++) {
            if (dup[i] != matched[i]) {
                break;
            }
        }
        if (i < wordsSize) {
            p += wordlen;
            continue;
        } 
        vector_append(&dst, p-s);
        p += batchlen;
    }
    root = trie_tree_destroy(root);

    free(dup);
    free(matched);

    *returnSize = dst.size;
    return dst.arr;
}

int
main(int argc, char *argv[]) {
    int i, *p;
    int size = 0;
    if (argc < 4) {
        printf("usage:%s string word1 word2 ...\n", argv[0]);
        return -1;
    }
    p = findSubstring(argv[1], argv+2, argc-2, &size);
    for (i = 0; i < size; i++) {
        printf("[%d]", p[i]);
    }
    printf("\n");
    return 0;
}

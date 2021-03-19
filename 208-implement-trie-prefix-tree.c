#include <stdlib.h>

#define MAX_NODE 26

typedef struct {
    char c;
    char fin;
    void *children[MAX_NODE];
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie *root = (Trie *)calloc(1, sizeof(Trie));
    return root;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    for (; '\0' != *word; word++) {
        if (NULL == obj->children[*word - 'a']) {
            obj->children[*word - 'a'] = (Trie *)calloc(1, sizeof(Trie));
            // obj = obj->children[*word - 'a']->c = word;
        }
        obj = (Trie *)(obj->children[*word - 'a']);
    }
    obj->fin = 1; /* 完整一个词 */
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    for (; '\0' != *word; word++) {
        obj = (Trie *)(obj->children[*word - 'a']);
        if (NULL == obj) {
            return false;
        }
    }
    return obj->fin == 1;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    for (; '\0' != *prefix; prefix++) {
        obj = (Trie *)(obj->children[*prefix - 'a']);
        if (NULL == obj) {
            return false;
        }
    }
    return true;
}

void trieFree(Trie* obj) {
    int i;
    if (NULL == obj) {
        return;
    }
    for (i = 0; i < MAX_NODE;i ++) {
        if (NULL != obj->children[i]) {
            trieFree((Trie *)(obj->children[i]));
        }
    }
    free(obj);
}


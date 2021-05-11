#include <stdlib.h>

#define CHILD_NUM 26
typedef struct {
    char fin;
    void *children[CHILD_NUM];
    
} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
    return (WordDictionary *)calloc(1, sizeof(WordDictionary));
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    while ('\0' != *word) {
        if (obj->children[*word - 'a'] == NULL) {
            obj->children[*word - 'a'] = (WordDictionary *)calloc(1, sizeof(WordDictionary));
        }
        obj = (WordDictionary *)obj->children[*word - 'a'];
        word++;
    }
    obj->fin = 1;
}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
    int i;
    WordDictionary *p = NULL;
    while ('\0' != *word) {
        if ('.' == *word) {
            for (i = 0; i < CHILD_NUM; i++) {
                p = (WordDictionary *)obj->children[i];
                if (NULL !=  p && wordDictionarySearch(p, word+1)) {
                    return true;
                }
            }
            return false;
        }
        obj = (WordDictionary *)obj->children[*word - 'a'];
        if (NULL == obj) {
            return false;
        }
        word++;
    }
    return obj->fin == 1;
}

void wordDictionaryFree(WordDictionary* obj) {
    int i;
    for (i = 0; i < CHILD_NUM; i++) {
        if (NULL == obj->children[i]) {
            continue;
        }
        wordDictionaryFree((WordDictionary *)obj->children[i]);
    }
    free(obj);
}

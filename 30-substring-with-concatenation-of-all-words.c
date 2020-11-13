#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/vector.h"

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    int i;
    int word_len = strlen(words[0]);
    int batch_len = word_len * wordsSize;
    const char *end   = strlen(s) + s;
    const char *begin = s;
    int offset    = 0;
    int match_cnt = 0;
    int match     = 0;

    struct Vector dst;
    vector_init(&dst);

    int *visited = (int *)malloc(sizeof(int) * wordsSize);
    for (; s+batch_len <= end; s++) {
        match_cnt = 0;
        memset(visited, 0, sizeof(int) * wordsSize);
        for (offset = 0; offset + s < end; offset += word_len) {
            match = 0;
            for (i = 0; i < wordsSize; i++) {
                if (!visited[i]) {
                    if (strncmp(s+offset, words[i], word_len) == 0) {
                        visited[i] = 1;
                        match      = 1;
                        match_cnt += 1;
                        break;
                    }
                }
            }
            /* 没有匹配n个词中的任意一个 */
            if (0 == match) {
                break;
            }
        }
        if(match_cnt == wordsSize) {
            vector_append(&dst, (int)(s-begin));
        }
    }
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

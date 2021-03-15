#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

struct Result {
    char **strs;
    uint64_t *hashs;
    int size;
    int capacity;
};

int has_existed(uint64_t hash, struct Result *head) {
    int i; 
    /* 判重 */
    for (i = 0; i < head->size; i++) {
        if (hash == head->hashs[i]) {
            return 1;
        }
    }
    return 0;
}

void append_result(const char *str, int len, uint64_t hash, struct Result *head) {
    if (head->strs == NULL) {
        head->size     = 0;
        head->capacity = 4;
        head->strs  = (char **)malloc(sizeof(char *) * head->capacity);
        head->hashs = (uint64_t *)malloc(sizeof(uint64_t) * head->capacity);
    }
    if (head->size == head->capacity) {
        head->capacity *= 2;
        head->strs  = (char **)realloc(head->strs, sizeof(char *) * head->capacity);
        head->hashs = (uint64_t *)realloc(head->hashs, sizeof(uint64_t ) * head->capacity);
    }

    head->strs[head->size] = (char *)malloc(len + 1);
    strncpy(head->strs[head->size], str, len);
    *(head->strs[head->size] + len) = '\0';
    head->hashs[head->size] = hash;
    head->size += 1;
    return;
}



char ** findRepeatedDnaSequences(char * s, int* returnSize){
    // int i, len;
    uint64_t h, hash = 0LU;
    const static int SIZE = 10;
    const static uint64_t MASK = 0XFFFFFFFFFFLLU;
    int table[26] = {0};
    // char buff[11];
    char *q, *p = s;
    struct Result head = {NULL, NULL, 0, 0};

    table['A' - 'A'] = 1;
    table['C' - 'A'] = 2;
    table['G' - 'A'] = 3;
    table['T' - 'A'] = 4;

    for (p = s; '\0' != *p; p++) {
        if ((p - s) == (SIZE - 1)) {
            break;
        }
        hash = (hash << 4) | (table[*p - 'A']);
    }

    while ('\0' != *p) {
        hash  = (hash << 4) | (table[*p - 'A']);
        hash &= MASK;
        h = hash;
        for (q = p+1; '\0' != *q; q++) {
            h  = (h << 4) | (table[*q - 'A']);
            h &= MASK;
            if (h == hash && !has_existed(hash, &head)) {
                append_result(q + 1 - SIZE, 10, hash, &head);
                break;
            }
        }
        p++;
    }

    *returnSize = head.size;
    return head.strs;
}

int
main(int argc, char *argv[]) {
    char **strs;
    int i, size = 0;
    if (argc < 2) {
        printf("usage:%s string\n", argv[0]);
        return -1;
    }
    strs = findRepeatedDnaSequences(argv[1], &size);
    for (i = 0; i < size; i++) {
        printf("%s\n", strs[i]);
    }
    return 0;
}

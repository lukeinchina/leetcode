#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *left_align_padding(char **words, int wordsSize, int width) {
    int i, offset = 0;
    char *buff = (char *)malloc(width+1);
    for (i = 0; i < wordsSize; i++) {
        strcpy(buff+offset, words[i]);
        offset += strlen(words[i]);
        if (i+1 == wordsSize) {
            while (offset < width) {
                buff[offset++] = ' ';
            }
            buff[offset] = '\0';
        } else {
            buff[offset++] = ' ';
        }
    }
    return buff;
}

/* 两端对齐. wordsSize >= 2 */
char *ends_align_padding(char **words, int wordsSize, int width) {
    int i, j, avg, left, total_len, offset;
    char *buff = (char *)malloc(width+1);
    total_len = 0;
    for (i = 0; i < wordsSize; i++) {
        total_len += strlen(words[i]);
    }
    avg  = (width - total_len) / (wordsSize - 1);
    left = (width - total_len) % (wordsSize - 1);
    offset = 0;
    for (i = 0; i < wordsSize; i++) {
        strcpy(buff+offset, words[i]);
        if (i+1 == wordsSize) {
            /* 最后一个词 */
            break;
        }
        offset += strlen(words[i]);
        for (j = 0; j < avg; j++) {
            buff[offset++] = ' ';
        }
        /* 左边多加一个空格 */
        if (left > 0) {
            buff[offset++] = ' ';
            left--;
        }
    }
    return buff;
}


char ** append_solution(char **lines, int *size, char *solution) {
    if (0 == *size) {
        lines = (char **)malloc(sizeof(char *));
    } else {
        lines = (char **)realloc(lines, (1+*size) * sizeof(char *));
    }
    lines[*size] = solution;
    *size += 1;
    return lines;
}

char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize){
    int i, idx, len, word_len, need_width;
    char *p, **pp = NULL;
    *returnSize = 0;
    i = 0;
    while (i < wordsSize) {
        word_len = 0;
        for (idx = i; i < wordsSize; i++) {
            len = strlen(words[i]);
            need_width = len + word_len + i - idx;
            if (need_width > maxWidth) {
                break;
            }
            word_len += len;
        }
        if (i == wordsSize || i-idx == 1) {
            p = left_align_padding(words+idx, i-idx, maxWidth);
        } else {
            p = ends_align_padding(words+idx, i-idx, maxWidth);
        }
        pp = append_solution(pp, returnSize, p);
    }
    return pp;
}

int
main(int argc, char *argv[]) {
    char **pp;
    int i, size;
    if (argc < 3) {
        printf("usage:%s width args...\n", argv[0]);
        return 0;
    }

    // printf("[%s]\n", ends_align_padding(argv+2, argc-2, atoi(argv[1])));
    pp = fullJustify(argv+2, argc-2, atoi(argv[1]), &size);
    for (i = 0; i < size; i++) {
        printf("%s\n", pp[i]);
    }
    return 0;
}

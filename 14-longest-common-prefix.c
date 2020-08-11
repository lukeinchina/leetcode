#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    char *p = NULL;
    int i, idx;
    if (strsSize < 1) {
        return "";
    }
    p = strs[0];
    for (idx = 0; '\0' != *(p+idx); idx++) {
        for (i = 1; i < strsSize; i++) {
            if (*(p+idx) != *(strs[i] + idx)) {
                break;
            }
        }
        if (i < strsSize) {
            break;
        }
    }
    p = (char *)malloc(idx+1);
    memcpy(p, strs[0], idx);
    *(p+idx) = '\0';
    return p;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s str1 str2 ...\n", argv[0]);
        return -1;
    }
    printf("%s\n", longestCommonPrefix(argv+1, argc-1));
    return 0;
}

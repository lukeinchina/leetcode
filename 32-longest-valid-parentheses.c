#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestValidParentheses(char * s){
    char *bottom = (char *)malloc(strlen(s)+1);
    char *top = bottom;
    int max = 0;
    int len = 0;
    for (; '\0' != *s; s++) {
        if ('(' == *s) {
            *top++ = *s;
            continue;
        }
        /* */
        if (top > bottom) {
            top--;
            len += 2;
        } else {
            len = 0;
        }
        if (len > max) {
            max = len;
        }
    }

    free(bottom);
    return max;
}

int
main(int argc ,char *argv[]) {
    if (argc < 2) {
        printf("usage:%s string\n", argv[0]);
        return -1;
    }
    printf("%s : %d\n", argv[1], longestValidParentheses(argv[1]));
    return 0;
} 

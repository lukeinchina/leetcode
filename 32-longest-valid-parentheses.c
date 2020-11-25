#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestValidParentheses(char * s){
    const char *p = s;
    int max, left, right;
    max = left = right = 0;
    for (p = s ; '\0' != *p; p++) {
        if ('(' == *p) {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            max = max > 2*left ? max : 2*left;
        } else if (right > left) {
            right = left = 0;
        }
    }
    left = right = 0;
    /* skip '\0' */
    for (--p; p >= s; p--) {
        if ('(' == *p) {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            max = max > 2*left ? max : 2*left;
        } else if (right < left) {
            right = left = 0;
        }
    }

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

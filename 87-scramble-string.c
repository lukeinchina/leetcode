#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DSIZE 26

bool is_equal(const char *s1, const char *e1, 
        const char *s2, const char *e2) {
    while (s1 <= e1 && s2 <= e2) {
        if (*s1++ != *s2++) {
            return false;
        }
    }
    return true;
}

bool is_requal(const char *s1, const char *e1, 
        const char *s2, const char *e2) {
    while (s1 <= e1 && s2 <= e2) {
        if (*s1++ != *e2-- || *s2++ != *e1--) {
            return false;
        }
    }
    return true;
}

bool helper(const char *s1, const char *e1, 
        const char *s2, const char *e2) {
    int i = 0;
    if (s1 > e1 || s2 > e2) {
        return false;
    } else if (s1 == e1 && s2 == e2) {
        return *s1 == *s2;
    } else if (is_equal(s1, e1, s2, e2) || is_requal(s1, e1, s2, e2)) {
        return true;
    }
    for (i = 1; s1+i <= e1; i++) {
        if ((helper(s1, s1+i-1, s2, s2+i-1) && helper(s1+i, e1, s2+i, e2)) ||
            (helper(s1, s1+i-1, e2-i+1, e2) && helper(s1+i, e1, s2, e2-i))) {
            return true;
        }
    }
    return false;
}


bool isScrambleRecursive(char * s1, char * s2){
    int len = strlen(s1);
    if (strlen(s2) != len) {
        return false;
    }

    return helper(s1, s1+len-1, s2, s2+len-1);
}

bool isScramble(char * s1, char * s2){
    int **dp = NULL;
    int i, len = strlen(s1);
    bool ok = false;
    if (len != strlen(s2)) {
        return false;
    }
    dp = (int **)malloc(sizeof(int *) * len);
    for (i = 0; i < len; i++) {
        dp[i] = (int *)calloc(len, sizeof(int));
    }
    for (i = 0; i < len; i++) {
        dp[i][i] = (s1[i] == s2[i]);
    }

    ok = (dp[0][len-1] == 1);
    for (i = 0; i < len; i++) {
        free(dp[i]);
    }
    free(dp);
    return  ok;
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage:%s str1 str2\n", argv[0]);
        return -1;
    }
    // printf("%s:%s-->%d\n", argv[1], argv[2], isScramble(argv[1], argv[2]));
    printf("%s:%s-->%d\n", argv[1], argv[2], isScrambleRecursive(argv[1], argv[2]));
    return 0;
}

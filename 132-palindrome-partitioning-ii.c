#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int is_palindrome(const char *s, int begin, int end) {
    while (begin < end) {
        if (s[begin++] != s[end--]) {
            return 0;
        }
    }
    return 1;
}

/* 1 <= s.length <= 2000 */
int minCut(char * s) {
    int i, j, min;
    int len = strlen(s);
    int *dp = (int *)malloc(sizeof(int) * len);
    for (i = 0; i < len; i++) {
        dp[i] = i;
    }

    for (i = 1; i < len; i++) {
        if (is_palindrome(s, 0, i)) {
            dp[i] = 0;
            continue;
        }
        min = dp[i];
        for (j = 0; j < i; j++) {
            if (is_palindrome(s, j+1, i)) {
                min = (min > dp[j]+1 ? dp[j]+1 : min);
            }
        }
        dp[i] = min;
    }

    min = dp[len-1];
    free(dp);
    return min;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s string\n", argv[0]);
        return -1;
    }
    printf("%s:%d\n", argv[1], minCut(argv[1]));
    return 0;
}

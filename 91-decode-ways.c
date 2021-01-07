#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num_decode(const char *s, int i, int *dp) {
    const char *p = s+i;

    /* 已经计算过 */
    if (dp[i] != -1) {
        return dp[i];
    }

    if ('\0' == *p) {
        dp[i] = 1;
    } else if ('0' == *p) {
        dp[i] = 0;
    } else if ('\0' == *(p+1)) {
        dp[i] = 1;
    } else if ('0' == *(p+1)) {
        dp[i] = num_decode(s, i+2, dp);
    } else if (*p > '2' || ('2' == *p && '6' < *(p+1))) {
        dp[i] = num_decode(s, i+1, dp);
    } else {
        dp[i] = num_decode(s, i+1, dp) + num_decode(s, i+2, dp);
    }
    return dp[i];
}

int numDecodings(char * s){
    int i, v, *dp;
    int len = strlen(s);
    if (len == 0) {
        return 0;
    }

    dp = (int *)malloc(sizeof(int) * (len+1));
    dp[len]   = 1;
    dp[len-1] = *(s+len-1) == '0' ? 0 : 1;
    for (i = len - 2; i >= 0; i--) {
        if ('0' == *(s+i)) {
            dp[i] = 0;
        } else if ('2' < *(s+i) || ('2' == *(s+i) && *(s+i+1) > '6')) {
            dp[i] = dp[i+1];
        } else {
            dp[i] = dp[i+1] + dp[i+2];
        }
    }
    v = dp[0];
    free(dp);
    return v;
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage:%s n\n", argv[0]);
        return -1;
    }
    printf("%d\n", numDecodings(argv[1]));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isInterleave(char * s1, char * s2, char * s3){
    int i,j;
    bool ok   = false;
    char **dp = NULL;
    int n = strlen(s1);
    int m = strlen(s2);
    if (m + n != strlen(s3)) {
        return false;
    }
    dp = (char **)malloc(sizeof(char *) * (n+1));
    for (i = 0; i <= n; i++) {
        dp[i] = (char *)calloc(m+1, sizeof(char));
    }
    /* dp[i][j] 表示 s3的前i+j 字符是否可以有s1的前i个字符
     *  和 s2的前j个字符来交叉而成
     **/
    dp[0][0] = 1;
    for (i = 1; i <= m && s2[i-1] == s3[i-1]; i++) {
        dp[0][i] = 1;
    }
    for (i = 1; i <= n && s1[i-1] == s3[i-1]; i++) {
        dp[i][0] = 1;
    }

    /* */
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            dp[i][j]  = (s1[i-1] == s3[j+i-1]) && dp[i-1][j];
            dp[i][j] |= (s2[j-1] == s3[i+j-1]) && dp[i][j-1];
        }
    }
    ok = dp[n][m];
    /* free */
    for (i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    return ok;
}

int
main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("usage:%s s1 s2 s3\n", argv[0]);
        return -1;
    }
    printf("%d\n", isInterleave(argv[1], argv[2], argv[3]));
    return 0;
}

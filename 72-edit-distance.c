#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minDistance(char * word1, char * word2){
    int i,j, size1, size2, min, **dp;
    size1 = strlen(word1)+1;
    size2 = strlen(word2)+1;
    if (size1 == 1 || size2 == 1) {
        return size1+size2-2;
    }
    dp = (int **)malloc(sizeof(int *) * size1);
    for (i = 0; i < size1; i++) {
        dp[i] = (int *)malloc(sizeof(int) * size2);
    }
    for (i = 0; i < size2; i++) {
        dp[0][i] = i;
    }
    for (i = 0; i < size1; i++) {
        dp[i][0] = i;
    }
    for (i = 1; i < size1; i++) {
        for (j = 1; j < size2; j++) {
            if (*(word1+i-1) == *(word2+j-1)) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                min = dp[i][j-1] > dp[i-1][j] ? dp[i-1][j] : dp[i][j-1];
                dp[i][j] = (dp[i-1][j-1] > min ? min : dp[i-1][j-1]) + 1;
            }
        }
    }
    min = dp[size1-1][size2-1];
    for (i = 0; i < size1; i++) {
        free(dp[i]);
    }
    free(dp);
    return min;
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage:%s string1 string2\n", argv[0]);
    }
    printf("%d\n", minDistance(argv[1], argv[2]));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n){
    int i,j, total;
    int **dp = (int **)malloc(sizeof(int *) * m);
    for (i = 0; i < m; i++) {
        dp[i] = (int *)calloc(n, sizeof(int));
    }

    for (i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (i = 0; i < n; i++) {
        dp[0][i] = 1;
    }
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    total = dp[m-1][n-1];
    for (i = 0; i < m; i++) {
        free(dp[i]);
    }
    free(dp);
    return total;
}


int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage:%s m n\n", argv[0]);
        return 0;
    }
    printf("%d\n", uniquePaths(atoi(argv[1]), atoi(argv[2])));
}

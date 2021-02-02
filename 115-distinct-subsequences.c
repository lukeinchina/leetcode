#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define do_swap(a, b) { \
    tmp = a; \
    a = b; \
    b = tmp; \
} while (0);

int num_distinct(char * s, char * t){
    if ('\0' == *t) {
        return 1;
    } else if ('\0' == *s) {
        return 0;
    }

    if (*s == *t) {
        return num_distinct(s+1, t+1) + num_distinct(s+1, t);
    }else {
        return num_distinct(s+1, t);
    }
}

long **create_matrix(int row, int col) {
    int i;
    long **matrix = (long **)malloc(row * sizeof(long *));
    for (i = 0; i < row; i++) {
        matrix[i] = (long *)calloc(col, sizeof(long));
    }
    return matrix;
}

void free_matrix(long **matrix, int row) {
    int i;
    for (i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int numDistinct(char * s, char * t){
    int i, j, val;
    long **dp;
    int m = strlen(s);
    int n = strlen(t);
    if (m < n || m < 1) {
        return 0;
    }
    dp = create_matrix(m+1, n+1);
    for (i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j];
            if (*(s+i-1) == *(t+j-1)) {
                dp[i][j] += dp[i-1][j-1];
            } 
        }
    }
    val = dp[m][n];
    free_matrix(dp, m+1);
    return val;
}

int numDistinct_O(char * s, char * t){
    long val, i, j, *prev, *curr, *tmp;
    long m = strlen(s);
    long n = strlen(t);
    if (m < n || m < 1) {
        return 0;
    }
    prev = (long *)calloc(m+1, sizeof(long));
    curr = (long *)calloc(m+1, sizeof(long));
    curr[0] = prev[0] = 1;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            curr[j] = prev[j];
            if (t[i-1] == s[j-1]) {
                curr[j] += prev[j-1];
            }
        }
        do_swap(prev, curr);
    }
    val = prev[n];
    free(prev);
    free(curr);
    return val;
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage:%s str1 str2\n", argv[0]);
        return -1;
    }
    
    printf("dp:%d\n",numDistinct(argv[1], argv[2])); 
    printf("recusive:%d\n", num_distinct(argv[1], argv[2]));
    return 0;
}

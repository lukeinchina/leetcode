#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int c,r, count, i;
    int **pp = (int **)malloc(sizeof(int *) * n);
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        pp[i] = (int *)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    *returnSize = n;

    c = 0; /* c ==> circle */
    count = 1;
    for (r = n; r > 0; r -= 2) {
        if (r == 1) {
            pp[c][c] = count++;
            break;
        }
        /* top */
        for (i = c; i < n-1-c; i++) {
            pp[c][i] = count++;
        }
        for (i = c; i < n-1-c; i++) {
            pp[i][n-1-c] = count++;
        }
        for (i = n-1-c; i > c; i--) {
            pp[n-1-c][i] = count++;
        }
        for (i = n-1-c; i > c; i--) {
            pp[i][c] = count++;
        }
        c += 1;
    }
    return pp;
}

int
main(int argc, char *argv[]) {
    int size = 0;
    int *cols = NULL;
    int **pp  = NULL;
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return -1;
    }
    pp = generateMatrix(atoi(argv[1]), &size, &cols);
    return 0;
}

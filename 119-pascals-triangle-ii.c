#include <stdlib.h>

#define do_swap(a, b) do {tmp = a; a = b; b = tmp;} while (0)

int* getRow(int rowIndex, int* returnSize){
    int n = rowIndex + 1;
    int i,j, *tmp;
    int *prev = (int *) calloc(n, sizeof(int));
    int *curr = (int *) calloc(n, sizeof(int));
    for (i = 0; i < n; i++) {
        curr[0] = curr[i] = 1;
        for (j = 1; j < i; j++) {
            curr[j] = prev[j] + prev[j-1];
        }
        do_swap(prev, curr);
    }
    free(curr);
    *returnSize = n;
    return prev;
}

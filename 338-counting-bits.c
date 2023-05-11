#include <stdio.h>
#include <stdlib.h>

int* countBits(int n, int* returnSize){
    int i, v, cnt;
    int *ans = (int *)malloc(sizeof(int) * (n+1));
    *returnSize = n + 1;
    for (i = 0; i < n + 1; i++) {
        v   = i;
        cnt = 0;
        while (v) {
            cnt += (v & 0X01);
            v >>= 1;
        }
        ans[i] = cnt;
    }
    return ans;
}

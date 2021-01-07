#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define swap(a, b) do {temp = a; a = b; b = temp;} while(0)

void print_array(const int *nums, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1==size ? '\n' : '\t');
    }
}

int comb(int *nums, int n, int l, int *dst, int index, int k, int **result, int *res_idx) {
    int i;
    if (index == k) {
        result[*res_idx] = (int *)malloc(sizeof(int) * k);
        memcpy(result[*res_idx], dst, k*sizeof(int));
        *res_idx += 1;
        return 0;
    }
    for (i = l; i < n; i++) {
        dst[index] = nums[i];
        comb(nums, n, i+1, dst, index+1, k, result, res_idx);
    }
    return 0;
}

/*
int comb_cnt(int n, int k) {
    if (k == n || k == 0) {
        return 1;
    } else if (k == 1) {
        return n;
    } else {
        return comb_cnt(n-1, k-1) + comb_cnt(n-1, k);
    }
}
*/

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int i, count = 0;
    long sub, total;
    int *nums, *dst, **pp;
    if (0 == k) {
        *returnSize = 0;
        return NULL;
    }
    sub = total = 1;
    for (i = 1; i <= k; i++) {
        total *= n + 1 - i;
        sub *= i;
    }
    total /= sub;
    nums = (int *)malloc(sizeof(int) * n);
    dst  = (int *)malloc(sizeof(int) * k);
    pp  = (int **)malloc(sizeof(int *) * total);
    *returnColumnSizes = (int *)malloc(sizeof(int) * total);
    for (i = 0; i < total; i++) {
        (*returnColumnSizes)[i] = k;
    }
    for (i = 0; i < n; i++) {
        nums[i] = i+1;
    }
    comb(nums, n, 0, dst, 0, k, pp, &count);
    free(nums);
    *returnSize = total;
    return pp;
}

int
main(int argc, char *argv[]) {
    int **pp;
    int i, size = 0;
    int *cols;
    if (argc < 3) {
        printf("usage:%s n k\n", argv[0]);
        return -1;
    }
    pp = combine(atoi(argv[1]), atoi(argv[2]), &size, &cols);
    for (i = 0; i < size; i++) {
        print_array(pp[i], atoi(argv[2]));
    }
//        printf("%d\n", comb_cnt(atoi(argv[1]), atoi(argv[2])));
    return 0;
}

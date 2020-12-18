#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a, b) do {temp = a; a = b; b = temp;} while(0)

void print_array(const int *nums, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1==size ? '\n' : '\t');
    }
}

int comb(int *nums, int n, int *dst, int index, int size) {
    int i, temp;
    if (index == size) {
        print_array(dst, size);
        return 0;
    }
    for (i = 0; i < n; i++) {
        swap(nums[i], nums[0]);
        dst[index] = nums[0];
        comb(nums+1, n-1, dst, index+1, size);
        swap(nums[i], nums[0]);
    }
    return 0;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int i;
    int *nums = (int *)malloc(sizeof(int) * n);
    int *dst  = (int *)malloc(sizeof(int) * k);
    for (i = 0; i < n; i++) {
        nums[i] = i+1;
    }
    comb(nums, n, dst, 0, k);
    free(nums);
    return NULL;
}

int
main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("usage:%s n k\n", argv[0]);
        return -1;
    }
    combine(atoi(argv[1]), atoi(argv[2]), NULL, NULL);
    return 0;
}

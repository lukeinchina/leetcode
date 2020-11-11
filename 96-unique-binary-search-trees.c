#include <stdio.h>
#include <stdlib.h>

int numTrees(int n){
    int i, j, sum;
    int nums[64] = {1, 1, 2, 5};
    for (i = 3; i <= n; i++) {
        sum = 0;
        for (j = 0; j < i; j++) {
            sum += nums[j] * nums[i-1-j];
        }
        nums[i] = sum;
    }
    return nums[n];
}

int
main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s n\n", argv[0]);
        return 0;
    }
    printf("%d\n", numTrees(atoi(argv[1])));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void sort_desc(int *nums, int size) {
    int i,j, temp;
    for (i = 0; i < size; i++) {
        for (j = i+1; j < size; j++) {
            if (nums[i] < nums[j]) {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int coinChange(int* coins, int coinsSize, int amount){
    int i,j, min;
    int *dp = (int *)calloc(amount + 1, sizeof(int));

    sort_desc(coins, coinsSize);
    for (i = 1; i <= amount; i++) {
        min = INT_MAX;
        for (j = 0; j < coinsSize; j++) {
            if (i >= coins[j] && dp[i-coins[j]] >= 0 && 
                    dp[i-coins[j]] + 1 < min) {
                min = dp[i-coins[j]] + 1;
            }
        }
        dp [i] = (min < INT_MAX ? min : -1);
    }
    min = dp[amount];
    free(dp);
    return min;
}

void print_array(const int *nums, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1 == size ? '\n': '\t');
    }
}

int
main(int argc, char *argv[]) {
    int n = -1;
    int amount = 0;
    int coins[] = {2, 5};
    if (argc == 2) {
        amount = atoi(argv[1]);
    }
    sort_desc(coins, sizeof(coins) / sizeof(coins[0]));
    n = coinChange(coins, sizeof(coins) / sizeof(coins[0]), amount);
    print_array(coins, sizeof(coins) / sizeof(coins[0]));
    printf("amount=%d, need %d\n", amount, n);
    return 0;
}

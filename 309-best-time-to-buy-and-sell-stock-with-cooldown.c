#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize){
    int i, end, max, asc = 1;
    int *dp = NULL;

    /* 初试化，第一个递增区间 [begin, end]*/
    for (i = 1; i < pricesSize && prices[i-1] >= prices[i]; i++) {
    }
    if (i >= pricesSize) {
        return 0;
    }

    dp    = (int *)calloc(pricesSize, sizeof(int));
    dp[i] = prices[i] - prices[i-1];
    end   = i;
    for (i += 1; i < pricesSize ; i++) {
        if (prices[i] < prices[i-1]) {
            dp[i] = dp[i-1];
            asc   = 0;
            continue;
        } else if (prices[i] == prices[i-1]) {
            dp[i] = dp[i-1];
            continue;
        }

        /* 继续递增 */
        if (end == i-1 || 1 == asc) {
            dp[i] = dp[i-1] + prices[i] - prices[i-1];
            end    = i;
        } else if (end == i-2)  {
            /* i-3, i-2(end), [i-1, i](递增), 缺乏cooldown位置，需要预留出来 */
            if (dp[i-2] > dp[i-3] + prices[i] - prices[i-1]) {
                max = dp[i-2];
            } else {
                max = dp[i-3] + prices[i] - prices[i-1];
                end = i;
            }

            /* 合并两个区间 ？*/
            if (max < dp[i-2] + prices[i] - prices[i-2]) {
                max = dp[i-2] + prices[i] - prices[i-2];
                end = i;
            }
            dp[i] = max;
        } else {
            /* i-3, i-2(cooldown), [i-1, i](递增) */
            dp[i] = dp[i-3] + prices[i] - prices[i-1];
            end   = i;
        }
        asc = 1;
    }

    for (i = 0; i < pricesSize; i++) {
        printf("%d%c", prices[i], i+1 == pricesSize ? '\n' : '\t');
    }
    for (i = 0; i < pricesSize; i++) {
        printf("%d%c", dp[i], i+1 == pricesSize ? '\n' : '\t');
    }

    max = dp[pricesSize-1];
    free(dp);
    return max;
}


int
main(void) {
    // int nums[] = {1, 7, 2, 1, 9, 7, 9};
    int nums[] = {1,4,7,5,6,2,5,1,9,7,9,7,0,6,8};

    printf("%d\n", maxProfit(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}

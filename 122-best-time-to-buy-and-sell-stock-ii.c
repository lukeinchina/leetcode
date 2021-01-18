#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
    int i, max = 0;
    for (i = 1; i < pricesSize; i++) {
        max += (prices[i] - prices[i-1] > 0 ? prices[i] - prices[i-1] : 0);
    }
    return max;
}

int
main(void) {
    int nums[] = {7,1,5,3,6,4, 1,2,3,4,5};
    printf("%d\n", maxProfit(nums, sizeof(nums)/sizeof(nums[0])));
    return 0;
}

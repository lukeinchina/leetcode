#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
    int i, sum, max;
    sum = max = 0;
    for (i = 1; i < pricesSize; i++) {
        sum += prices[i] - prices[i-1];
        if (sum < 0) {
            sum = 0;
        }
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}

int
main(void) {
    int nums[] = {7,1,5,3,6,4};
    printf("%d\n", maxProfit(nums, sizeof(nums)/sizeof(nums[0])));
    return 0;
}

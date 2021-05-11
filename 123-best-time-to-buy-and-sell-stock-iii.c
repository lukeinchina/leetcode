#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
    int begin, end;
    int i, max = 0;
    for (i = 1; i < pricesSize; i++) {
    }
    max = max_profit(prices, pricesSize, &begin, &end);
    return max;
}


int
main(void) {
    // int nums[] = {7,1,5,3,6,4, 1,2,3,4,5};
    int nums[] = {3,3,5,0,0,3,1,4};
    printf("%d\n", maxProfit(nums, sizeof(nums)/sizeof(nums[0])));
    return 0;
}

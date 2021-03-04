#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int i = 0;
    int j = numbersSize - 1;
    int *rst = (int *)malloc(sizeof(int) * 2);

    while (i < j) {
        if (numbers[i] + numbers[j] > target) {
            j--;
        } else if (numbers[i] + numbers[j] < target) {
            i++;
        } else {
            break;
        }
    }
    rst[0] = i;
    rst[1] = j;
    *returnSize = 2;
    return rst;
}

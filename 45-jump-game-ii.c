#include <stdio.h>

int jump(int* nums, int numsSize){
    int i,last_index, max_pos, step, end;
    end = max_pos = step = 0;
    last_index = numsSize - 1;
    for (i = 0; i < last_index; i++) {
        if (max_pos < i+nums[i]) {
            max_pos = i + nums[i];
        }
        if (i == end) {
            end = max_pos;
            step++;
        }
    }
    return step;
}

int
main(void) {
    int array[] = {2,3,1,1,4};
    printf("%d\n", jump(array, sizeof(array)/sizeof(array[0])));
    return 0;
}

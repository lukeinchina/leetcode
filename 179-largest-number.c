#include <stdio.h>
#include <stdlib.h>

int compare(const void *left, const void *right) {
    int a = *(int *)left;
    int b = *(int *)right;
    static char buff_l[24];
    static char buff_r[24];
    int i, n;
    if (0 == a || 0 == b) {
        return b - a;
    }
    n = snprintf(buff_l, sizeof(buff_l), "%d%d", a, b);
    n = snprintf(buff_r, sizeof(buff_r), "%d%d", b, a);
    for (i = 0; i < n; i++) {
        if (buff_r[i] != buff_l[i]) {
            return buff_r[i] - buff_l[i];
        }
    }
    return 0;
}

int need_length(const int nums[], int size) {
    int i, n, cnt, total = 1;
    for (i = 0; i < size; i++) {
        cnt = (0 == nums[i] ? 1 : 0);
        for (n = nums[i]; n > 0; n /= 10) {
            cnt++;
        }
        total += cnt;
    }
    return total;
}

char * largestNumber(int* nums, int numsSize){
    int i, offset, left;
    int size = need_length(nums, numsSize);
    char *buff = (char *)malloc(size);
    qsort(nums, numsSize, sizeof(nums[0]), compare);
    if (nums[0] == nums[numsSize-1] && 0 == nums[0]) {
        buff[0] = '0';
        buff[1] = '\0';
        return buff;
    }
    offset = 0;
    left = size;
    for (i = 0; i < numsSize; i++) {
        offset += snprintf(buff+offset, left, "%d", nums[i]);
        left = size - offset;
    }
    return buff;
}

void print_array(const int nums[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d%c", nums[i], i+1 == size ? '\n' : '\t');
    }
}

int
main(void) {
    int nums[] = {0, 0};
    int len = need_length(nums, sizeof(nums) / sizeof(nums[0]));
    printf("%d\n", len);
//    print_array(nums, sizeof(nums) / sizeof(nums[0]));
    print_array(nums, sizeof(nums) / sizeof(nums[0]));
    printf("%s\n", largestNumber(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}

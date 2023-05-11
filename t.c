#include <stdio.h>
#include <stdlib.h>

int compare(const void *l, const void *r) {
    return (*(const int *)l - *(const int *)r);
}

int can_swap(int nums[], int begin, int end) {
    for (; begin < end; begin++) {
        if (nums[begin] == nums[end]) {
            return 0;
        }
    }
    return 1;
}

#define do_swap(a, b) { \
            temp      = nums[idx];\
            nums[idx] = nums[i];\
            nums[i]   = temp;\
        }while(0)
void perm(int *nums, int size, int idx) {
    int i,temp;
    if (idx+1 == size) {
        for (i = 0; i < size; i++) {
            printf("%d%c", nums[i], i+1 == size ? '\n' : '\t');
        }
        return;
    }
    for (i = idx; i < size; i++) {
        if (!can_swap(nums, idx, i)) {
            continue;
        }else {
            do_swap(nums[idx], nums[i]);
            perm(nums, size, idx+1);
            do_swap(nums[idx], nums[i]);
        }
    }
}

int slove(std::vector<int> &n, int h) {
}

int
main(void) {
    int nums[] = {5, 10, 20};
    std::vector<int> n;
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        n.append(nums[i]);
    }
    printf("speed:%d\n", slove(n, 4));
    return 0;
}

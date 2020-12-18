#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target){

}

int
main(int argc, char *argv[]) {
    int nums[] = {2,5,6,0,0,1,2};
    if (argc < 2) {
        printf("usage:%s k\n", argv[0]);
        return -1;
    }
    printf("%d\n", search(nums, sizeof(nums)/sizeof(nums[0]), atoi(argv[1])));
    return 0;
}


int singleNumber(int* nums, int numsSize){
    int i, n;
    for (n = i = 0; i < numsSize; i++) {
        n ^= nums[i];
    }
    return n;
}

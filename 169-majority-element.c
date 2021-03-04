
int majorityElement(int* nums, int numsSize){
    int i, major = nums[0];
    int count = 1;
    for (i = 1; i < numsSize; i++) {
        if (major == nums[i]) {
            count++;
            continue;
        }
        if (--count < 0) {
            count = 1;
            major = nums[i];
        }
    }
    return major;
}


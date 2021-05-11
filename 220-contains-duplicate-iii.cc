#include <stdio.h>
#include <limits.h>
#include <vector>
#include <map>

using namespace std;

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t){
    return false;
}

inline
long bucket_no(long v, long t) {
    return v / (t + 1);
}
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int size = nums.size();
    long key, width = t;
    width += 1;
    map<long, long>::const_iterator left, right, it;
    map<long, long> bucket;
    for (int i = 0; i < size; i++) {
        key = bucket_no(nums[i], t);

        it  = bucket.find(key);
        if (bucket.end() != it) {
            return true;
        }
        it = bucket.insert(pair<long, long>(key, nums[i]));

        if (bucket.size() >= k) {
            bucket.erase(nums[i+1-k]);
        }
    }
}

int
main(void) {
    // int nums[] = {7,1,3};
    // int nums[] = {1,2,3,1,5,9};
    int nums[] = {2147483647, -1, 2147483647};
    int k = 3;
    int t = 1;

    bool has = containsNearbyAlmostDuplicate(nums, sizeof(nums) / sizeof(nums[0]), k, t);
    printf("%d\n", has);
    return 0;
}

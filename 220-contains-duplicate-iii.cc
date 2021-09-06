#include <stdio.h>
#include <limits.h>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k) {
    int i, size = nums.size();
    set<int> s;
    for (i = 0; i <= k; i++) {
        if (s.count(nums[i]) > 0) {
            return true;
        }
        s.insert(nums[i]);
    }
    for (; i < size; i++) {
        s.erase(nums[i-k-1]);
        if (s.count(nums[i]) > 0) {
            return true;
        }
        s.insert(nums[i]);
    }
    return false;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int i, size = nums.size();
    long key, w = t;
    if (0 == t) {
        return  containsNearbyDuplicate(nums, k);
    }
    map<long, long>::const_iterator left, right, it;
    map<long, long> bucket;
    for (i = 0; i < size; i++) {
        key = (nums[i] > 0 ? nums[i] / w : nums[i] / w - 1);
        it  = bucket.find(key);
        if (bucket.end() != it) {
            printf("find: %d:%d\n", it->second, nums[i]);
            return (nums[i] > it->second ? nums[i] - it->second : it->second - nums[i]) <= w;
        }
        it = bucket.insert(pair<long, long>(key, nums[i])).first;

        right = left = it;
        if (bucket.begin() != left) {
            left--;
            if (nums[i] - left->second <= w) {
                printf("left find\n");
                return true;
            }
        }
        
        right++;
        if (bucket.end() != right && right->second - nums[i] <= w) {
            printf("right find\n");
            return true;
        }

        if (bucket.size() > k) {
            key = (nums[i-k] > 0 ? nums[i-k] / w : nums[i-k] / w - 1);
            bucket.erase(key);
        }
    }
    return false;
}

int
main(void) {
    // int nums[] = {7,1,3};
    int nums[] = {1,5,9,1,5,9};
    vector<int> vec;
    int k = 2;
    int t = 3;

    for (size_t i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        vec.push_back(nums[i]);
    }
    bool has = containsNearbyAlmostDuplicate(vec, k, t);
    printf("%d\n", has);
    return 0;
}

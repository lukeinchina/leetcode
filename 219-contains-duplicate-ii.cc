#include <set>
#include <vector>
using namespace std;


bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    int i, j;
    for (j = 1; j <= k; j++) {
        for (i = 0; i + j < numsSize; i++) {
            if (nums[i] == nums[j+i]) {
                return true;
            }
        }
    }
    return false;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
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

int
main(void) {
    int nums[] = {1,2,3,1,2,3};
    int k = 3;

    vector<int> vec(nums, nums + 6);
    bool has = containsNearbyDuplicate(vec, k);
    printf("%d\n", has);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <map>

using namespace std;

void max_min(const vector<int> &nums, int &max, int &min) {
    int size = nums.size();
    min = max = nums[0];
    for (int i = 1; i < size; i++) {
        max = (max < nums[i] ? nums[i] : max);
        min = (min > nums[i] ? nums[i] : min);
    }
}

int nbucket(int count) {
    int n ;
    n = (int)sqrt(count);
    return n;
}

vector<int> countSmaller(vector<int>& nums) {
    vector<int> dst(nums.size());

    map<int, int> id_map;
    map<int, int>::iterator it;

    for (int i = nums.size() - 1; i >= 0; i--) {
        it = id_map.upper_bound(nums[i]);
    }
}

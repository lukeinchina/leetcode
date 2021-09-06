#include <stdio.h>
#include <deque>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int i, size = nums.size() + 1 - k;
    vector<int> dst;
    deque<int> q;

    for (i = 0; i < k-1; i++) {
        while (!q.empty() && q.back() < nums[i]) {
            q.pop_back();
        }
        q.push_back(nums[i]);
    }
    for (i = 0; i < size; i++) {
        while (!q.empty() && q.back() < nums[i+k-1]) {
            q.pop_back();
        }
        q.push_back(nums[i+k-1]);

        dst.push_back(q.front());

        if (nums[i] == q.front()) {
            q.pop_front();
        }
    }

    return dst;
}

int 
main(int argc, char *argv[]) {
//     int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int nums[] = {1,0};
    int i, size;
    vector<int> vec;
    size = sizeof(nums) / sizeof(nums[0]);
    for (i = 0; i < size; i++) {
        vec.push_back(nums[i]);
    }
    vector<int> dst = maxSlidingWindow(vec, 1);
    for (i = 0; i < dst.size(); i++) {
        printf("%d\n", dst[i]);
    }
    return 0;
}

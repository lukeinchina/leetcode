#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> rst;
    int i, size1 = nums1.size();
    int j, size2 = nums2.size();
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    i = j = 0;
    while (i < size1  && j < size2) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else if (rst.size() > 0 && rst[rst.size()-1] == nums1[i]) {
            i++;
            j++;
        } else {
            rst.push_back(nums1[i++]);
            j++;
        }
    }
    return rst;
}

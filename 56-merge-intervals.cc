#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
struct PairLess {
    bool operator(const vector<int> &left, const vector<int> &right) {
        return left[0] < right[0];
    }
};
*/
bool comp_start(const vector<int> &left, const vector<int> &right) {
    return left[0] < right[0];
}

vector<vector<int> > merge(vector<vector<int> >& intervals) {
    vector<vector<int> > dst;
    sort(intervals.begin(), intervals.end(), comp_start);
    int size = intervals.size();
    int i, idx, start, end;
    idx = i = 0;
    while (idx < size) {
        start = intervals[idx][0];
        end   = intervals[idx][1];
        for (i = idx+1; i < size && intervals[i][0] <= end ; i++) {
            end = (intervals[i][1] > end ? intervals[i][1] : end);
        }
        idx = i;
        vector<int> a;
        a.push_back(start);
        a.push_back(end);
        dst.push_back(a);
    }
    size = dst.size();
    for(int i = 0; i < size; i++) {
        printf("[%d %d]", dst[i][0], dst[i][1]);
    }
    printf("\n");
    return dst;
}

int
main(void) {
    vector<vector<int> > intervals;
    int array[][2] = {{1,3}, {2,8}, {8,10}, {15,18}};
    for (int i = 0; i < 4; i++) {
        vector<int> a ;
        a.push_back(array[i][0]);
        a.push_back(array[i][1]);
        intervals.push_back(a);
    }
    merge(intervals);
    return 0;
}

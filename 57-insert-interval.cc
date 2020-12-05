#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
    int size, i, start, end;
    vector<vector<int> > dst;
    size = intervals.size();
    start = newInterval[0];
    end   = newInterval[1];
    for (i = 0; i < size && intervals[i][1] < start; i++) {
        dst.push_back(intervals[i]);
    }
    if (i < size) {
        start = (start > intervals[i][0] ? intervals[i][0] : start);
        while (i < size && intervals[i][0] <= end) {
            if (intervals[i][1] > end) {
                end = intervals[i][1];
                i  += 1;
                break;
            } else {
                i += 1;
            }
        }
    }
    newInterval[0] = start;
    newInterval[1] = end;
    dst.push_back(newInterval);
    for (; i < size; i++) {
        dst.push_back(intervals[i]);
    }
    return dst;
}

int
main(void) {
    vector<vector<int> > intervals;
    vector<int> item;
    item.push_back(1); item.push_back(5);
    int array[][2] = {{1,7}, {3,5}, {6,7}, {8,10}, {12,16}};
    for (int i = 0; i < 1; i++) {
        vector<int> a ;
        a.push_back(array[i][0]);
        a.push_back(array[i][1]);
        intervals.push_back(a);
    }
    vector<vector<int> > dst = insert(intervals, item);
    for (int i = 0; i < dst.size(); i++) {
        printf("[%d %d]", dst[i][0], dst[i][1]);
    }
    printf("\n");
    return 0;
}

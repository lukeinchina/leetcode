#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {
private:
    int count;
    priority_queue <int, vector<int>, greater<int> > min_heap;
    priority_queue <int> max_heap;
public:
    MedianFinder() {
        max_heap.push(-2147483648);
        min_heap.push(2147483647);
    }
    
    void addNum(int num) {
        if (num > max_heap.top()) {
            min_heap.push(num);
        } else {
            max_heap.push(num);
        }
        if (max_heap.size() > min_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()+1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        count++;
    }
    
    double findMedian() {
        if (count % 2) {
            return min_heap.top();
        } else {
            return (max_heap.top() + min_heap.top()) * 0.5;
        }
    }
};


int
main(void) {
    return 0;
}

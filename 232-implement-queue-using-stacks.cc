#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> s1; /* tail */
    stack<int> s2; /* head */
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x;
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        x = s2.top();
        s2.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (!s2.empty()) {
            return s2.top();
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

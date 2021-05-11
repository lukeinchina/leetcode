#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> a;
    queue<int> b;
    
	int swap(queue<int> &h, queue<int> &e) {
		int v = h.back();
		while(h.size() > 1) {
			e.push(h.front());
			h.pop();
		}
		h.pop();
        return v;
	}

public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
		if (a.empty()) {
			b.push(x);
		}else {
			a.push(x);
		}
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		if (a.empty()) {
			return swap(b, a);
		} else {
			return swap(a, b);
		}
    }
    
    /** Get the top element. */
    int top() {
		if (a.empty()) {
			return b.back();
		} else {
			return a.back();
		}
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return a.empty() && b.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

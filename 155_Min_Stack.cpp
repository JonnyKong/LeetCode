/**
 * Greedy O(1);
 */

class MinStack {
private:
    stack<int> stk;
    stack<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        stk.push(x);
        if(min.empty() || x <= min.top())
            min.push(x);
    }

    void pop() {
        if(min.top() == stk.top())
            min.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min.top();
    }
};
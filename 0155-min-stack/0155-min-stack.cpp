class MinStack {
    stack<long long> a;
    long long mini;

public:
    MinStack() {}

    void push(int value) {
        if (a.empty()) {
            mini = value;
            a.push(value);
        } else if (value > mini)
            a.push(value);
        else {
            a.push(2LL * value - mini);
            mini = value;
        }
    }

    void pop() {
        if (a.empty())
            return;
        if (a.top() > mini)
            a.pop();
        else {
            mini = 2LL * mini - a.top();
            a.pop();
        }
        return;
    }

    int top() {
        if (a.empty())
            return -1;
        long long x = a.top();
        if (mini < x)
            return x;
        return mini;
    }

    int getMin() { return mini; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
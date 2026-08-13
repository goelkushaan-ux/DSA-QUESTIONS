class MyStack {
    queue<int> a;
    queue<int> b;

public:
    MyStack() {}

    void push(int x) { a.push(x); }

    int pop() {
        while (a.size() > 1) {
            b.push(a.front());
            a.pop();
        }

        int x = a.front();
        a.pop();

        while (!b.empty()) {
            a.push(b.front());
            b.pop();
        }

        return x;
    }

    int top() {
        while (a.size() > 1) {
            b.push(a.front());
            a.pop();
        }

        int x = a.front();

        b.push(a.front());
        a.pop();

        while (!b.empty()) {
            a.push(b.front());
            b.pop();
        }

        return x;
    }

    bool empty() { return a.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
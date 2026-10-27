class MedianFinder {
    priority_queue<int> low;                             // max-heap
    priority_queue<int, vector<int>, greater<int>> high; // min heap
public:
    MedianFinder() {}

    void addNum(int num) {
        if (low.empty()) {
            low.push(num);
            return;
        }
        int a = low.top(), b;
        if (num <= a)
            low.push(num);
        else {
            high.push(num);
            b = high.top();
            high.pop();
            low.push(b);
        }
        int n = low.size();
        int m = high.size();
        if (n == m || n == m + 1)
            return;
        if (n == m + 2) {
            int top = low.top();
            low.pop();
            high.push(top);
        } else if (n + 1 == m) {
            int top = high.top();
            high.pop();
            low.push(top);
        }
    }

    double findMedian() {
        int n = low.size();
        int m = high.size();
        if (n > m)
            return low.top();
        double ans = (high.top() + low.top()) / 2.0;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
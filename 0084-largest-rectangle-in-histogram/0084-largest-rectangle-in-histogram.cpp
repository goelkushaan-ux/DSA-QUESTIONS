class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 1)
            return heights[0];
        vector<int> nse(n, n), pse(n, -1);
        stack<int> a;
        for (int i = 0; i < n; i++) {
            while (!a.empty() && heights[a.top()] >= heights[i])
                a.pop();
            if (!a.empty())
                pse[i] = a.top();
            a.push(i);
        }
        while (a.empty() != true)
            a.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!a.empty() && heights[a.top()] >= heights[i])
                a.pop();
            if (!a.empty())
                nse[i] = a.top();
            a.push(i);
        }
        int area = 0;
        for (int i = 0; i < n; i++) {
            area = max(area, heights[i] * (nse[i] - pse[i] - 1));
        }
        return area;
    }
};
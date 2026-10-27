class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> f(26, 0);
        for (int i = 0; i < tasks.size(); i++)
            f[tasks[i] - 'A']++;
        priority_queue<int> a;
        for (int i = 0; i < 26; i++)
            if (f[i] > 0)
                a.push(f[i]);
        int ans = 0;
        while (!a.empty()) {
            int count = 0;
            int cycle = n + 1;
            vector<int> temp;
            while (cycle > 0 && !a.empty()) {
                int top = a.top();
                a.pop();
                if (top - 1 > 0)
                    temp.push_back(top - 1);
                count++;
                cycle--;
            }
            for (int i = 0; i < temp.size(); i++)
                a.push(temp[i]);
            if (a.empty())
                ans += count;
            else
                ans += n + 1;
        }
        return ans;
    }
};
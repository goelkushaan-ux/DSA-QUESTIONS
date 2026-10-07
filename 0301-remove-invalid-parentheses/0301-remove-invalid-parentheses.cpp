class Solution {
public:
    bool valid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(')
                count++;
            else if (c == ')') {
                count--;
                if (count < 0)
                    return false;
            }
        }
        return count == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q;
        set<string> visited;
        q.push(s);
        visited.insert(s);
        int l = -1;
        while (!q.empty() ) {
            string a = q.front();
            q.pop();
            if (l != -1 && a.size() != l)
                break;
            if (valid(a) == true) {
                ans.push_back(a);
                l = a.size();
            }
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != '(' && a[i] != ')')
                    continue;
                string temp = a.substr(0, i) + a.substr(i + 1);
                if (visited.find(temp) == visited.end()) {
                    visited.insert(temp);
                    q.push(temp);
                }
            }
        }
        return ans;
    }
};
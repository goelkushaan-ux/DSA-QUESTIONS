class Solution {
public:
    int minInsertions(string s) {
        stack<char> temp;
        int ans = 0;
        int a = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (a == 1) {
                    if (!temp.empty()) {
                        ans += 1;
                        temp.pop();
                    } else
                        ans += 2;
                }
                a = 0;
                temp.push(s[i]);
            } else {
                if (a == 0)
                    a = 1;
                else {
                    if (temp.empty())
                        ans += 1;
                    else
                        temp.pop();
                    a = 0;
                }
            }
        }
        if (!temp.empty())
            ans += temp.size() * 2 - a;
        else if (a == 1)
            ans += 2;
        return ans;
    }
};
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k || k == 0)
            return "0";
        stack<char> ans;
        for (int i = 0; i < num.size() ; i++) {
            while (ans.empty() != true && k > 0 && ans.top() > num[i]) {
                ans.pop();
                k--;
            }
            ans.push(num[i]);
            if (ans.size() == 1 && num[i] == '0')
                ans.pop();
        }
        while (k && !ans.empty()) {
            k--;
            ans.pop();
        }

        string res = "";
        while (!ans.empty()) {
            res.push_back(ans.top());
            ans.pop();
        }
        reverse(res.begin(), res.end());
        if (res.length() == 0)
            return "0";

        return res;
    }
};
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int a = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                a++;
            else
                a--;
            if (a < 0)
                ans++, a = 0;
        }
        if (a > 0)
            ans += a;
        return ans;
    }
};
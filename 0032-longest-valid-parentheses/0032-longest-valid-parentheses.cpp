class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 2)
            return 0;
        long long left = 0, right = 0;
        long long count = 0;
        long long ans = 0;
        while (right < s.size()) {
            if (s[right] == '(')
                count++, right++;
            else
                count--, right++;
            if (count < 0) {
                left = right;
                count = 0;
            }
            if (count == 0)
                ans = max(ans, right - left);
        }
        left = s.size() - 1;
        right--,count=0;
        while (right >= 0) {
            if (s[right] == ')')
                count++, right--;
            else
                count--, right--;
            if (count < 0) {
                left = right;
                count = 0;
            }
            if (count == 0)
                ans = max(ans, left - right);
        }
        return ans;
    }
};
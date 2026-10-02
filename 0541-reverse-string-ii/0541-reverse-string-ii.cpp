class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            int l = i;
            int r = min(i + k - 1, (int)s.size() - 1);
            while (l < r) {
                char a = s[l];
                s[l] = s[r];
                s[r] = a;
                l++;
                r--;
            }
        }
        return s;
    }
};
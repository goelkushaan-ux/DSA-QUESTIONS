class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (s[i] == ' ')
            i--;
        int ans = 0;
        for (i; i >= 0 && s[i] != ' '; i--)
            ans++;
        return ans;
    }
};
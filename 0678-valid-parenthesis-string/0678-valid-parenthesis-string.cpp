class Solution {
public:
    bool checkValidString(string s) {
        int maxi = 0, mini = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                maxi++, mini++;
            else if (s[i] == ')')
                maxi--, mini--;
            else {
                mini--;
                maxi++;
            }
            if (maxi < 0)
                return false;
            mini = max(0, mini);
        }
        if (mini == 0)
            return true;
        return false;
    }
};
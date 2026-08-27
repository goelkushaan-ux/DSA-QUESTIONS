class Solution {
public:
    void check(string s, vector<vector<string>>& ans, int ind,
               vector<string>& temp) {
        if (ind == s.length()) {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < s.length(); i++) {
            if (pal(s, ind, i)) {
                temp.push_back(s.substr(ind, i - ind + 1));
                check(s, ans, i + 1, temp);
                temp.pop_back();
            }
        }
    }
    bool pal(string s, int i, int j) {
        while (i <= j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        check(s, ans, 0, temp);
        return ans;
    }
};
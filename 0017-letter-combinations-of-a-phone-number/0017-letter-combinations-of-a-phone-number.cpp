class Solution {
public:
    string combos[10] = {"",    "",    "abc",  "def", "ghi",
                         "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void pat(string& digits, vector<string>& ans, int i, string temp) {
        if (i == digits.length()) {
            ans.push_back(temp);
            return;
        }
        int d = digits[i] - '0';
        for (int j = 0; j < combos[d].size(); j++) {
            temp.push_back(combos[d][j]);
            pat(digits, ans, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        pat(digits, ans, 0, temp);
        return ans;
    }
};
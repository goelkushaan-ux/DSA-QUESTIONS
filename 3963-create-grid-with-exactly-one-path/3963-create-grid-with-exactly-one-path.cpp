class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string s = "";
        for (int i = 0; i < n; i++)
            s += '.';
        ans.push_back(s);
        for (int i = 0; i < m - 1; i++) {
            s = "";
            for (int j = 0; j < n; j++) {
                if (j == (n - 1))
                    s += '.';
                else
                    s += '#';
            }
            ans.push_back(s);
        }
        return ans;
    }
};
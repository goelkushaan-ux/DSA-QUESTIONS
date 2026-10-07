class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() == 1)
            return s;
        vector<int> a(s.size());
        int k = 0;
        int d = 1;
        for (int i = 0; i < s.size(); i++) {
            a[i] = k;
            if (k == 0)
                d = 1;
            else if (k == numRows - 1)
                d = 0;
            if (d == 1)
                k++;
            else
                k--;
        }
        string ans = "";
        for (int i = 0; i < numRows; i++)
            for (int j = 0; j < s.size(); j++)
                if (a[j] == i)
                    ans += s[j];
        return ans;
    }
};
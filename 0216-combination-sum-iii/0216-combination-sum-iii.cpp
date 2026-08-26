class Solution {
public:
    void findCombination(int num, int sum, int count, vector<vector<int>>& ans,
                         vector<int>& ds) {
        if (sum == 0 && count == 0) {
            ans.push_back(ds);
            return;
        }
        if (count == 0 || sum <= 0 || num > min(9, sum))
            return;
        for (int i = num; i <= min(sum, 9); i++) {
            ds.push_back(i);
            findCombination(i + 1, sum - i, count - 1, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if (n > 45 - (9 - k) * (10 - k) / 2)
            return ans;
        vector<int> ds;
        findCombination(1, n, k, ans, ds);
        return ans;
    }
};
class Solution {
public:
    void findCombination(int i, int k, vector<int>& nums,
                         vector<vector<int>>& ans, vector<int>& ds) {
        if (i == nums.size()) {
            if (k == 0)
                ans.push_back(ds);
            return;
        }
        if (nums[i] <= k) {
            ds.push_back(nums[i]);
            findCombination(i, k - nums[i], nums, ans, ds);
            ds.pop_back();
        }
        findCombination(i + 1, k, nums, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
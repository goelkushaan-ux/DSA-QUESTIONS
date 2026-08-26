class Solution {
public:
    void comb(vector<int> nums, int i, int k, vector<vector<int>>& ans,
              vector<int>& temp) {
        if (k == 0) {
            ans.push_back(temp);
            return;
        }
        if (i == nums.size() || k < 0)
            return;
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1])
                continue;
            if (nums[j] > k)
                break;
            temp.push_back(nums[j]);
            comb(nums, j + 1, k - nums[j], ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        comb(candidates, 0, target, ans, temp);
        return ans;
    }
};
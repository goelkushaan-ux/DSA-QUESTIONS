class Solution {
public:
    void comb(vector<int> nums, int i, vector<vector<int>>& ans,
              vector<int>& temp) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        comb(nums, i + 1, ans, temp);
        temp.pop_back();
        comb(nums, i + 1, ans, temp);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        comb(nums, 0, ans, temp);
        return ans;
    }
};
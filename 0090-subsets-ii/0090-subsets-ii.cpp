class Solution {
public:
void comb(vector<int> nums, int i, vector<vector<int>>& ans,
              vector<int>& temp) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }
        ans.push_back(temp);
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1])
                continue;
            if (i == nums.size())
                break;
            temp.push_back(nums[j]);
            comb(nums, j + 1, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        comb(nums, 0,  ans, temp);
        return ans;
    }
};
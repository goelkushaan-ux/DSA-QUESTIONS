class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.insert({nums[i], nums[j], nums[k]});
                    j++, k--;
                }
                if (sum > 0)
                    k--;
                if (sum < 0)
                    j++;
            }
        }
        vector<vector<int>> a(ans.begin(), ans.end());
        return a;
    }
};
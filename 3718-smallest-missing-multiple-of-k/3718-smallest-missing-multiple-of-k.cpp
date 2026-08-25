class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1;
        for (int i = 0; i < nums.size(); i++)
            if (ans * k == nums[i])
                ans++;
        return ans * k;
    }
};
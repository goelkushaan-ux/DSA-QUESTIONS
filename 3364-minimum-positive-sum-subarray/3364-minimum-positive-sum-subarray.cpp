class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for (int len = l; len <= r; len++) {
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                if (i >= len)
                    sum -= nums[i - len];
                if (i >= len - 1 && sum > 0 && sum < ans)
                    ans = sum;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
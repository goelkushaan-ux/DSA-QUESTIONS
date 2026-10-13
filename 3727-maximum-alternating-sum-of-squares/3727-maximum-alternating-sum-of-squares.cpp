class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            nums[i] = abs(nums[i]);
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        while (l <= r) {
            if (l == r) {
                ans += 1LL * nums[r] * nums[r];
                break;
            }
            ans += 1LL * nums[r] * nums[r] - 1LL * nums[l] * nums[l];
            l++, r--;
        }
        return ans;
    }
};
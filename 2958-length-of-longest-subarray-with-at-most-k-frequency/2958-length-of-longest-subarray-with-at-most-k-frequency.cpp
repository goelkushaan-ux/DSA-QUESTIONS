class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if (freq[nums[i]] <= k)
                ans = max(ans, i - left + 1);
            while (freq[nums[i]] > k) {
                freq[nums[left]]--;
                left++;
            }
        }
        return ans;
    }
};
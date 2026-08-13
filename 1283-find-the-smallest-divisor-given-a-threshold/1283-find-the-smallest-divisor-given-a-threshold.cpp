class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, h = *max_element(nums.begin(), nums.end());
        int ans = h;
        while (l <= h) {
            long long mid = (l + h) / 2, r = 0;
            for (int i = 0; i < nums.size(); i++)
                r += (nums[i]+mid-1 )/ mid;
            if (r <= threshold) {
                ans = mid;
                h = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int h = nums[0];
        for (auto a : nums) {
            mp[a]++;
            if (mp[h] < mp[a])
                h = a;
        }
        int degree = mp[h];
        if (degree < 2)
            return 1;
        int ans = INT_MAX;

        for (auto a : mp) {
            if (a.second == degree) {
                int l = INT_MAX, r = 0;
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] == a.first) {
                        l = min(l, i + 1);
                        r = i + 1;
                    }
                }
                ans = min(ans, r - l + 1);
            }
        }
        return ans;
    }
};
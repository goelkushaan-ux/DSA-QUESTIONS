class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (auto a : nums)
            if (a > maxi)
                maxi = a;
        int ans = 0;
        for (auto a : nums)
            ans += abs(maxi - a);
        return ans;
    }
};
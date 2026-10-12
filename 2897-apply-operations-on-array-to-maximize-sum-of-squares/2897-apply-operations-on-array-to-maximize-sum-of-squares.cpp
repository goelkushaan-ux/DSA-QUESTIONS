class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        int n = nums.size();

        int a[32] = {0};
        for (int x : nums)
            for (int b = 0; b < 31; b++)
                if ((x >> b) & 1)
                    a[b]++;
        for (int i = 0; i < k; i++) {
            long long x = 0;
            for (int b = 0; b < 31; b++)
                if (a[b] > 0)
                    x = x | (1 << b), a[b]--;
            ans = (ans + x * x) % MOD;
        }
        return ans % MOD;
    }
};
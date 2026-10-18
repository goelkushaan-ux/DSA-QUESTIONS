class Solution {
    long long MOD = 1000000007;
    long long power(long long a, long long b) {
        long long ans = 1;
        while (b > 0) {
            if (b % 2)
                ans = ans * a % MOD;
            a = a * a % MOD;
            b /= 2;
        }
        return ans;
    }

    long long perm(int a, int b) {
        long long ans = 1;
        for (int i = 1; i <= b; i++) {
            ans = ans * (a - i + 1) % MOD;
            ans = ans * power(i, MOD - 2) % MOD;
        }
        return ans;
    }

    long long check(vector<int> nums) {
        if (nums.size() < 2)
            return 1;
        vector<int> small, large;
        long long ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[0])
                small.push_back(nums[i]);
            else
                large.push_back(nums[i]);
        }
        int a = small.size(), b = large.size();
        ans = (perm(a + b, a)) % 1000000007;
        ans = (ans * check(small)) % 1000000007;
        ans = (ans * check(large)) % 1000000007;
        return ans;
    }

public:
    int numOfWays(vector<int>& nums) {
        long long ans = check(nums);
        return (ans - 1 + 1000000007) % 1000000007;
    }
};
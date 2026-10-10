class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();
        vector<long long> diff;
        long long sum = 0;
        long long maxi = 0;
        for (int i = 0; i < n; i++) {
            long long a = abs(nums1[i] - nums2[i]);
            diff.push_back(a);
            sum += a;
            maxi = max(maxi, a);
        }
        long long k = (long long)k1 + k2;
        if (k >= sum)
            return 0;
        vector<long long> count(maxi + 1, 0);
        for (int i = 0; i < n; i++)
            count[diff[i]]++;
        for (int i = maxi; i > 0 && k > 0; i--) {
            if (count[i] == 0)
                continue;
            if (k >= count[i]) {
                count[i - 1] += count[i];
                k -= count[i];
                count[i] = 0;
            } else {
                count[i] -= k;
                count[i - 1] += k;
                k = 0;
            }
        }
        long long ans = 0;
        for (int i = 1; i <= maxi; i++)
            ans += count[i] * i * i;
        return ans;
    }
};
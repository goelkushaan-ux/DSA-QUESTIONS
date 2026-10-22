class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int best = INT_MAX;
        int k = nums[0];
        bool isA = true;
        for (int i = 0; i < n && isA; i++)
            if (nums[i] != (k + i) % n)
                isA = false;
        if (isA) {
            best = min(best, (n - k) % n);
            best = min(best, k + 2);
        }
        int c = nums[0];
        bool isB = true;
        for (int i = 0; i < n && isB; i++)
            if (nums[i] != ((c - i) % n + n) % n)
                isB = false;
        if (isB) {
            best = min(best, 1 + (n - c - 1) % n);
            best = min(best, (c + 1) % n + 1);
        }
        return best == INT_MAX ? -1 : best;
    }
};
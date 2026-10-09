class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});
        sort(a.begin(), a.end());
        long long score = 0;

        for (int i = 0; i < n; i++) {
            int val = a[i].first;
            int idx = a[i].second;
            if (nums[idx] == 0)
                continue;
            score += val;
            nums[idx] = 0;
            if (idx > 0)
                nums[idx - 1] = 0;
            if (idx < n - 1)
                nums[idx + 1] = 0;
        }
        return score;
    }
};
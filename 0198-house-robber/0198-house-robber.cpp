class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> a;
        a.push_back(nums[0]);
        if (nums.size() > 1)
            a.push_back(max(a[0], nums[1]));
        for (int i = 2; i < nums.size(); i++) {
            int x = max(a[i - 1], nums[i] + a[i - 2]);
            a.push_back(x);
        }
        return a[nums.size() - 1];
    }
};
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int sum = 0;
        for (auto a : nums)
            sum += a;
        int x = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (x == sum - x - nums[i])
                return i;
            x += nums[i];
        }
        return -1;
    }
};
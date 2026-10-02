class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        if (nums[0] == 0)
            return 0;
        for (int i = 1; i < nums.size(); i++) {
            int sum = 0;
            while (nums[i] > 0) {
                sum += nums[i] % 10;
                nums[i] /= 10;
            }
            if (sum == i && nums[i] == 0)
                return i;
        }
        return -1;
    }
};
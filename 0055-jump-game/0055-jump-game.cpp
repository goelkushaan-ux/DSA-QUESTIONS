class Solution {
public:
    bool canJump(vector<int>& nums) {
        int req = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < req)
                req++;
            if (nums[i] < req && i == 0)
                return false;
            if (nums[i] >= req)
                req = 1;
        }
        return true;
    }
};
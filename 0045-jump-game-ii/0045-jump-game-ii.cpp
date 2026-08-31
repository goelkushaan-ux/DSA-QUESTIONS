class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 3)
            return nums.size() - 1;
        int left = 0, right = 0, count = 0;
        while (right < nums.size() - 1) {
            int maxi=0;
            for (int i = left; i <= right; i++) {
                maxi=max(maxi,nums[i]+i);
            }
            count++;
            left=right+1;
            right=maxi;
        }
        return count;
    }
};
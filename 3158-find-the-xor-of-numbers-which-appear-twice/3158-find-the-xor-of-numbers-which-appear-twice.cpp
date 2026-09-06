class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int a[50] = {0};
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            a[nums[i] - 1]++;
            if (a[nums[i] - 1] == 2)
                ans ^= nums[i];
        }
        return ans;
    }
};
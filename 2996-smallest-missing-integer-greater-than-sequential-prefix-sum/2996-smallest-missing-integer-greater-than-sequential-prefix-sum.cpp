#include <algorithm>
class Solution {
public:
    int s(int n) {
        if (n < 1)
            return 0;
        return n * (n + 1) / 2;
    }
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }
        sort(nums.begin(), nums.end());
        for (int x = sum;; x++)
            if (!binary_search(nums.begin(), nums.end(), x))
                return x;
        return sum;
    }
};
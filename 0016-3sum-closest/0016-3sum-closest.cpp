class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long min_sum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i <= nums.size() - 3; i++) {
            int k = nums.size() - 1;
            for (int j = i + 1; j < k; j) {
                long long sum = nums[i] + nums[j] + nums[k];
                if (target == sum)
                    return sum;
                if (abs(target - sum) < abs(target - min_sum))
                    min_sum = sum;
                if (sum > target)
                    k--;
                else
                    j++;
            }
        }
        return min_sum;
    }
};
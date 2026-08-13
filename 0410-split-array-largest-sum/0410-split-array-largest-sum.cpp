class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int ans = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            int partitions = 1;   // at least one partition
            long subarraySum = 0; // sum of current subarray

            for (int num : nums) {
                if (subarraySum + num <= mid)
                    subarraySum += num;
                else {
                    partitions++;
                    subarraySum = num;
                }
            }
            if (partitions <= k) {
               ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};
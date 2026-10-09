class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int left = 0, right = nums.size() - 1;
        int ans = INT_MAX;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
                ans=min(ans,nums[mid]);
                left++, right--;
                continue;
            }
            if (nums[left] < nums[right]) {
                ans = min(ans, nums[left]);
                break;
            } else if (nums[mid] >= nums[left]) {
                ans = min(ans, nums[left]);
                left = mid + 1;
            } else {
                ans = min(ans, nums[mid]);
                right = mid - 1;
            }
        }
        return ans;
    }
};
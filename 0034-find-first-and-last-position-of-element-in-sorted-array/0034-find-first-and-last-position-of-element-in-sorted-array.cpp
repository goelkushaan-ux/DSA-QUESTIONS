class Solution {

    ///// find upper and lower values index

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int a = -1, b = -1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target)
                    a = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }
        
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target)
                    b = mid;
                right = mid - 1;
            } else
                left = mid + 1;
        }
        ans.push_back(b);
        ans.push_back(a);
        return ans;
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int left = 0, right = nums.size() - 1;
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[right]!=nums[right-1]) return nums[right]; 
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                return nums[mid];
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1]) ) left=mid+1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
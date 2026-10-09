class Solution {
    void mergesort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergesort(nums, low, mid);
        mergesort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
    void merge(vector<int>& nums, int l, int mid, int h) {
        vector<int> temp;
        int i = l;
        int j = mid + 1;
        while (i <= mid && j <= h) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= h) {
            temp.push_back(nums[j]);
            j++;
        }
        for (int k = l; k <= h; k++) 
            nums[k] = temp[k - l];
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};
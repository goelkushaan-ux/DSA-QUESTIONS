class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (temp.count(nums[i]))
                return true;
            temp.insert(nums[i]);
            if (temp.size() > k)
                temp.erase(nums[i - k]);
        }

        return false;
    }
};
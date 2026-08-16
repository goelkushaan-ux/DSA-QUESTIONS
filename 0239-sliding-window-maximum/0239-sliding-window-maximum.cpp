class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> a;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (a.empty() != true && a.front() <= i - k)
                a.pop_front();
            while (a.empty() != true && nums[a.back()] < nums[i])
                a.pop_back();
            a.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[a.front()]);
        }
        return ans;
    }
};
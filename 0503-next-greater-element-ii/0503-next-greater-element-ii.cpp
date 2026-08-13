class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> a;
        int n = nums.size();
        for (int i = 2 * nums.size() - 1; i >= 0; i--) {
            while (a.empty() != true && nums[i % n] >= a.top())
                a.pop();
            if(a.empty()!=true) ans[i % n] = a.top();
            else 
                ans[i % n] = -1;
            
            a.push(nums[i % n]);
        }
        return ans;
    }
};
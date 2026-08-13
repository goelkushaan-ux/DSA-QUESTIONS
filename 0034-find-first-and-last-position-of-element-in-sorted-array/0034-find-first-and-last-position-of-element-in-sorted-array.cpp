class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int a=-1, b=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(a==-1) a=i;
                b=i;
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
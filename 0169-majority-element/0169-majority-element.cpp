class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,a;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                a=nums[i];
                count++;
            }
            else if(a==nums[i]) count++;
            else count--;
        }
        count=0;
        for(int i=0;i<nums.size();i++) if(nums[i]==a) count++;
        if(count>nums.size()/2) return a;
        return a;
    }
};
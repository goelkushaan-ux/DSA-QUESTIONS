class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int a=1,b=1,n=nums.size();
        for(int i=0;i<n;i++){
            a*=nums[i];
            b*=nums[n-i-1];
            ans=max(ans,max(a,b));
            if(a==0)a=1;
            if(b==0) b=1;
        }
        return ans;
    }
};
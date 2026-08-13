class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)a++;
            if(nums[i]==1)b++;
            if(nums[i]==2)c++;
        }
        int k=0;
        while(a!=0){
            nums[k++]=0;
            a--;
        }
        while(b!=0){
            nums[k++]=1;
            b--;
        }
        while(c!=0){
            nums[k++]=2;
            c--;
        }
    }
};
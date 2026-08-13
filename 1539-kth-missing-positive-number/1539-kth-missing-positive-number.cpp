class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0,r=arr.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            int mis=arr[mid]-(mid+1);
            if(mis>=k) r=mid-1;
            else l=mid+1;
        }
        return r+k+1;
    }
};
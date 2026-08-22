class Solution {
public:
    bool checkDivisibility(int n) {
        int p=n;
        long long sum =0,product=1;
        while(n!=0){
            sum+=n%10;
            product*=n%10;
            n=n/10;
        }
        sum=sum+product;
        if(p%sum==0) return true;
        return false;
    }
};
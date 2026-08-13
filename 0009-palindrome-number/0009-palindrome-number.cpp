class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long int a=0,b=x;
        while(x!=0){
            a=a*10+x%10;
            x=x/10;
        }
        if(a==b) return true;
        return false;
    }
};
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int s = 0;
        while (sum != 0) {
            if (sum > 9)
                ans += '9', sum -= 9;
            else if (sum > 0) {
                ans += sum + '0';
                sum = 0;
            } else
                ans += '0';
            if (ans.size() > num)
                return "";
        }
        while(ans.size()<num) ans+='0';
        return ans;
    }
};
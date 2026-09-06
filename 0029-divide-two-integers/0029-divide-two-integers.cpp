class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
        int sign = 1;
        if (divisor < 0)
            sign = -1;
        if (dividend < 0)
            sign = -sign;
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long ans = 0;
        while (a >= b) {
            int p = 0;
            while (a >= (b << (p + 1)))
                p++;
            ans += (1LL << p);
            a -= b << p;
        }
        if (sign < 0)
            ans = -ans;
        if (ans < INT_MIN)
            return INT_MIN;
        if (ans > INT_MAX)
            return INT_MAX;
        return ans;
    }
};
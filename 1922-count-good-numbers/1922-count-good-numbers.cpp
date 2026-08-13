class Solution {
public:
    long long pow(long long x, long long n) {
        const long long MOD = 1e9 + 7;
        if (n == 0)
            return 1;
        long long half = pow(x, n / 2);
        half = (half * half) % MOD;
        if (n % 2 == 1)
            half = (half * x) % MOD;
        return half;
    }

    int countGoodNumbers(long long n) {
        const long long MOD = 1e9 + 7;
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        return (pow(5, even) * pow(4, odd)) % MOD;
    }
};
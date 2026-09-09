class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000)
            return 0;
        long long sum=0;
        long long z = 1000;
        while (z<=n) {
            sum += (n - z + 1) ;
            z = z * 1000;
        }
        return sum;
    }
};
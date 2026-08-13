class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long a = start ^ goal;
        int c = 0;
        for (int i = 0; a != 0; i++) {
            c += (a & 1);
            a = a >> 1;
        }
        return c;
    }
};
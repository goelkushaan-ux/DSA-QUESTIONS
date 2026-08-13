class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int sin = 1;
        int i=0;
        while (i < s.size() && s[i] == ' ')
            i++;
        if (i == s.size())
            return 0;
        if (s[i] == '+')
            i++;
        else if (s[i] == '-') {
            sin = -1;
            i++;
        }
        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + s[i] - '0';
            if (sin * num <= INT_MIN)
                return INT_MIN;
            if (sin * num >= INT_MAX)
                return INT_MAX;
            i++;
        }
        return num * sin;
    }
};
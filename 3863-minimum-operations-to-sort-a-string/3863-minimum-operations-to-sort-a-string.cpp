class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int mini = 0, maxi = 0;
        bool a = true;
        for (int i = 0; i < n; i++) {
            if (s[i] - 'a' < s[mini] - 'a')
                mini = i;
            if (s[i] - 'a' >= s[maxi] - 'a')
                maxi = i;
            if (i > 0 && s[i] - 'a' < s[i - 1] - 'a')
                a = false;
        }
        if (a == true)
            return 0;
        if (n == 2)
            return -1;
        if (mini == n - 1 && maxi == 0)
            return 3;
        if (s[mini] == s[0] || s[maxi] == s[n - 1])
            return 1;
        return 2;
    }
};
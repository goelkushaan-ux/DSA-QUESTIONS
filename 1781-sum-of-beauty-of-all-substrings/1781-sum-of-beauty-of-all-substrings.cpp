class Solution {
public:
    int beautySum(string s) {
        int ans = 0, n = s.size();
        for (int i = 0; i < s.size(); i++) {
            int arr[26] = {0};
            for (int j = i; j < s.size(); j++) {
                arr[s[j] - 'a']++;
                int mini = INT_MAX, maxi = INT_MIN;
                for (int k = 0; k < 26; k++) {
                    if (arr[k] > 0)
                        mini = min(mini, arr[k]);
                    maxi = max(maxi, arr[k]);
                }
                if (mini > 0 && mini<maxi)
                    ans += maxi - mini;
            }
        }
        return ans;
    }
};
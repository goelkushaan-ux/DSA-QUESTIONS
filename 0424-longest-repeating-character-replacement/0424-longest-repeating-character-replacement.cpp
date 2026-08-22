class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int maxcount = 0;
        int maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'A']++;
            maxcount = max(maxcount, freq[s[i] - 'A']);
            while ((i - left + 1) - maxcount > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            maxlength = max(maxlength, i - left + 1);
        }
        return maxlength;
    }
};
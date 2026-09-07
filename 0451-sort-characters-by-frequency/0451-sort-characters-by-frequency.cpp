class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> freq(128, {'0', 0});
        for (char c : s)
            freq[c].second++, freq[c].first = c;
        sort(freq.begin(), freq.end(),
             [](auto& a, auto& b) { return a.second > b.second; });
        string ans;
        for (auto& p : freq)
            if (p.second > 0)
                ans += string(p.second, p.first);
        return ans;
    }
};
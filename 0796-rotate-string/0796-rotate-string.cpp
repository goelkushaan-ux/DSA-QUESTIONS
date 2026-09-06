class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        for (int i = 0; i < s.size(); i++) {
            if (s == goal)
                return true;
            char a = s[0];
            s.erase(0, 1);
            s.push_back(a);
        }
        return false;
    }
};
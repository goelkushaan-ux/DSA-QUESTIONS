class Solution {
public:
    string reverseWords(string s) {
        int i = s.size() - 1;
        string result = "";
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ')
                i--;
            if (i < 0)
                return result;
            int end = i;
            while (i >= 0 && s[i] != ' ')
                i--;
            string word = s.substr(i + 1, end - i);
            if (!result.empty())
                result += " ";
            result += word;
        }
        return result;
    }
};
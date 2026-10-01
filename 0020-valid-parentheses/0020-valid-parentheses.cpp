class Solution {
public:
    bool isValid(string s) {
        stack<int> a;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                a.push(s[i]);
            else if(a.empty()) return false;
            else if ((s[i] == ')' && a.top() != '(') ||
                (s[i] == ']' && a.top() != '[') ||
                (s[i] == '}' && a.top() != '{') )
                return false;
            else
                a.pop();
        }
        return a.empty();
    }
};
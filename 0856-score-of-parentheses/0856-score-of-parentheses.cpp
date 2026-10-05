class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> ans={0};
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') ans.push_back(0);
            if(s[i]==')') {
                int inner=ans.back();
                ans.pop_back();
                ans.back()+=max(2*inner,1);
            }
        }
        return ans[0];
    }
};
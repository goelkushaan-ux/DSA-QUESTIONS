class Solution {
public:
    int maxDepth(string s) {
        int ans=0,a=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') a++;
            else if(s[i]==')') a--;
            ans=max(ans,a);
        }
        return ans;
    }
};
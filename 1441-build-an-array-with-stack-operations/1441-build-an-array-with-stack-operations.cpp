class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int a = 0;
        for (int i = 1; i <= n; i++) {
            ans.push_back("Push");
            if(i==target[target.size()-1]) break;
            if (i != target[a])
                ans.push_back("Pop");
            else
                a++;
        }
        return ans;
    }
};
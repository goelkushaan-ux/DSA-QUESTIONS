class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count=0;
        map<char,int> f;
        int left=0,right=0;
        while(right<s.size() && s.size()-left>=count){
            f[s[right]]++;
            while(f[s[right]]>1){
                f[s[left]]--;
                left++;
            }
            count=max(count,right-left+1);
            right++;
        }
        return count;
    }
};
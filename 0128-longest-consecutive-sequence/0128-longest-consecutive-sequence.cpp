class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++)
            st.insert(nums[i]);
        int len = 1;
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int count = 1, x = it;
                while (st.find(x + 1) != st.end())
                    x++, count++;
                len = max(len, count);
            }
        }
        return len;
    }
};
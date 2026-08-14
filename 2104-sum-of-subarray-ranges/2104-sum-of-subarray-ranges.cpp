class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        vector<int> nse(n), pse(n), nge(n),
            pge(n); // next smaller nd equal
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (st.empty() != true && nums[st.top()] >= nums[i])
                st.pop();
            if (st.empty())
                nse[i] = n - i;
            else
                nse[i] = st.top() - i;
            st.push(i);
        }
        while (st.empty() != true)
            st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (st.empty() != true && nums[st.top()] <= nums[i])
                st.pop();
            if (st.empty())
                nge[i] = n - i;
            else
                nge[i] = st.top() - i;
            st.push(i);
        }
        while (st.empty() != true)
            st.pop();

        for (int i = 0; i < n; i++) {
            while (st.empty() != true && nums[st.top()] > nums[i])
                st.pop();
            if (st.empty())
                pse[i] = i + 1;
            else
                pse[i] = i - st.top();
            st.push(i);
        }
        while (st.empty() != true)
            st.pop();

        for (int i = 0; i < n; i++) {
            while (st.empty() != true && nums[st.top()] < nums[i])
                st.pop();
            if (st.empty())
                pge[i] = i + 1;
            else
                pge[i] = i - st.top();
            st.push(i);
        }

        long long maxi = 0, mini = 0;
        for (int i = 0; i < n; i++) {
            mini = (mini + 1LL * nums[i] * nse[i] * pse[i]);
            maxi = (maxi + 1LL * nums[i] * nge[i] * pge[i]);
        }

        return maxi - mini;
    }
};
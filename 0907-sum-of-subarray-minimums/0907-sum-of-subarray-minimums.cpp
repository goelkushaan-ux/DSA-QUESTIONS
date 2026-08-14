class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return arr[0];
        vector<int> nse(n), pse(n); // next smaller nd equal
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (st.empty() != true && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                nse[i] = n - i;
            else
                nse[i] = st.top() - i;
            st.push(i);
        }
        while (st.empty() != true)
            st.pop();
        for (int i = 0; i < n; i++) {
            while (st.empty() != true && arr[st.top()] > arr[i])
                st.pop();
            if (st.empty())
                pse[i] = i + 1;
            else
                pse[i] = i - st.top();
            st.push(i);
        }
        const int MOD = 1e9 + 7;
        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans = (ans + 1LL * arr[i] * nse[i] * pse[i]) % MOD;
        return ans;
    }
};
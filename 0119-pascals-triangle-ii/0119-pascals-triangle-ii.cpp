class Solution {
public:
    long long fact(int n, int r) {
        if (r == 0)
            return 1;
        long long ans= n * fact(n - 1, r - 1) / r;
        return ans;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 0);
        for (int i = 0; i <= rowIndex / 2; i++) {
            int a = fact(rowIndex, i);
            ans[i] = a;
            ans[rowIndex - i] = a;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        long long m = (long long)n * n;
        long long a = 0;
        long long b = m * (m + 1) / 2;
        long long x = 0;
        long long y = (long long)m * (m + 1) * (2 * m + 1) / 6;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a += grid[i][j];
                x += (long long)grid[i][j] * grid[i][j];
            }
        }
        vector<int> ans;
        long long miss,r;
        miss=(b-a +(y-x)/(b-a))/2;
        long long sum = (y - x) / (b - a);
        r=sum-miss;
        ans.push_back(r);
        ans.push_back(miss);
        return ans;
    }
};
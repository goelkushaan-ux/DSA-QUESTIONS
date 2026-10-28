class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(1024, false)));
        dp[0][0][grid[0][0]] = true;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                for (int k = 0; k <= 1023; k++) {
                    if ((i > 0 && dp[i - 1][j][k]) ||
                        (j > 0 && dp[i][j - 1][k]))
                        dp[i][j][k ^ grid[i][j]] = true;
                }
            }
        }
        for (int i = 0; i <= 1023; i++)
            if (dp[m-1][n-1][i])
                return i;
        return -1;
    }
};
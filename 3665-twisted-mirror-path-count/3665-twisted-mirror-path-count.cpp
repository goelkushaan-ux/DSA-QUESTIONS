class Solution {
    int mod = 1000000007, m, n;
    vector<vector<int>> dp;
    long long count(vector<vector<int>>& grid, int i, int j) {
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        long long ans = 0;
        if (j < n - 1) {
            if (grid[i][j + 1] == 0)
                ans += count(grid, i, j + 1);
            else {
                int x = i, y = j + 1;
                bool right = true;
                while (x < m && y < n && grid[x][y] != 0) {
                    if (right == true)
                        x++, right = false;
                    else
                        y++, right = true;
                }
                if (x < m && y < n)
                    ans += count(grid, x, y);
            }
        }
        ans %= mod;
        if (i < m - 1) {
            if (grid[i + 1][j] == 0)
                ans += count(grid, i + 1, j);
            else {
                int x = i + 1, y = j;
                bool right = false;

                while (x < m && y < n && grid[x][y] != 0) {
                    if (right == true)
                        x++, right = false;
                    else
                        y++, right = true;
                }
                if (x < m && y < n)
                    ans += count(grid, x, y);
            }
        }
        return dp[i][j] = ans % mod;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<int>(n, -1));

        return count(grid, 0, 0);
    }
};
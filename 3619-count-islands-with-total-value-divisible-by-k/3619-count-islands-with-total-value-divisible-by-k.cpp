class Solution {
    int m, n;

public:
    long long dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 0;
        long long sum = grid[i][j];
        grid[i][j] = 0;
        long long a = dfs(grid, i + 1, j);
        long long b = dfs(grid, i - 1, j);
        long long c = dfs(grid, i, j + 1);
        long long d = dfs(grid, i, j - 1);
        return sum + a + b + c + d;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] != 0 && dfs(grid, i, j) % k == 0)
                    count++;
        return count;
    }
};
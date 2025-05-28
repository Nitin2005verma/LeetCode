class Solution {
    int helper(int m, int n, int x, int y, int stepCount, int totalSteps, vector<vector<int>>& grid) {
        if (grid[x][y] == 2)
            return stepCount == totalSteps ? 1 : 0;

        int ans = 0;
        int temp = grid[x][y];
        grid[x][y] = -1; // mark as visited

        if (x + 1 <= m && grid[x + 1][y] != -1)
            ans += helper(m, n, x + 1, y, stepCount + 1, totalSteps, grid);
        if (y + 1 <= n && grid[x][y + 1] != -1)
            ans += helper(m, n, x, y + 1, stepCount + 1, totalSteps, grid);
        if (x - 1 >= 0 && grid[x - 1][y] != -1)
            ans += helper(m, n, x - 1, y, stepCount + 1, totalSteps, grid);
        if (y - 1 >= 0 && grid[x][y - 1] != -1)
            ans += helper(m, n, x, y - 1, stepCount + 1, totalSteps, grid);

        grid[x][y] = temp; // backtrack
        return ans;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sx = 0, sy = 0, totalSteps = 0;

        // count walkable cells and find start
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != -1) totalSteps++;
                if (grid[i][j] == 1) sx = i, sy = j;
            }

        return helper(m - 1, n - 1, sx, sy, 1, totalSteps, grid);
    }
};

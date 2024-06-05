class Solution {
public:
    int minPathSumHelper(vector<vector<int>>& grid, int x, int y, int r, int c,
                         vector<vector<int>>& memo) {
        // Base case: if we reach the bottom-right cell, return its value
        if (x == r - 1 && y == c - 1) {
            return grid[x][y];
        }

        // If out of bounds, return a large number to avoid this path
        if (x >= r || y >= c) {
            return INT_MAX;
        }

        // Check if the result is already computed
        if (memo[x][y] != -1) {
            return memo[x][y];
        }

        // Recursively find the minimum path sum from the current cell to the
        // bottom-right cell
        int rightPath = minPathSumHelper(grid, x, y + 1, r, c, memo);
        int downPath = minPathSumHelper(grid, x + 1, y, r, c, memo);

        // Calculate the minimum path sum for the current cell
        int minPath = grid[x][y] + min(rightPath, downPath);

        // Memoize the result
        memo[x][y] = minPath;

        return minPath;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        if (r == 0) {
            return 0;
        }
        int c = grid[0].size();

        // Create a memoization table and initialize it with -1
        vector<vector<int>> memo(r, vector<int>(c, -1));

        // Start the recursion from the top-left cell (0, 0)
        return minPathSumHelper(grid, 0, 0, r, c, memo);
    }
};
class Solution {
public:
    void handleIsland(vector<vector<char>>& matrix, int x, int y, int r,
                      int c) {
        // Check if the current cell is out of bounds or not an island part
        // ('1')
        if (x < 0 || x >= r || y < 0 || y >= c || matrix[x][y] != '1') {
            return;
        }
        // Mark the current cell as visited by changing it to '2'
        matrix[x][y] = '2';

        // Recursively handle the neighboring cells (up, down, left, right)
        handleIsland(matrix, x + 1, y, r, c); // Down
        handleIsland(matrix, x, y + 1, r, c); // Right
        handleIsland(matrix, x - 1, y, r, c); // Up
        handleIsland(matrix, x, y - 1, r, c); // Left
    }

    int numIslands(
        vector<vector<char>>& grid) { // Corrected function name to numIslands
        int row = grid.size();
        if (row == 0) {
            return 0;
        }
        int col = grid[0].size();

        int Islands = 0;

        // Iterate through each cell in the grid
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // If the cell is an unvisited island part ('1'), handle the
                // island
                if (grid[i][j] == '1') {
                    handleIsland(grid, i, j, row, col);
                    Islands++;
                }
            }
        }
        return Islands;
    }
};
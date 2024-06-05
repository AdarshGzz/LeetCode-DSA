class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) {
            return;
        }
        int col = matrix[0].size();

        vector<bool> zeroRows(row, false);
        vector<bool> zeroCols(col, false);

        // First pass to find all the rows and columns that have zeroes.
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }

        // Second pass to set the elements to zero based on the zeroRows and
        // zeroCols arrays.
        for (int i = 0; i < row; ++i) {
            if (zeroRows[i]) {
                for (int j = 0; j < col; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < col; ++j) {
            if (zeroCols[j]) {
                for (int i = 0; i < row; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
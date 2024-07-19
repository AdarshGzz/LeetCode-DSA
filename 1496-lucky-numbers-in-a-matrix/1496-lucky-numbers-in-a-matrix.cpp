class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> rowMin(row, INT_MAX);
        vector<int> colMax(col, 0);

        // Find the minimum element in each row
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int e = matrix[i][j];
                rowMin[i] = min(rowMin[i], e);
                colMax[j] = max(colMax[j], e);
            }
        }

        // Find the lucky numbers
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int e = matrix[i][j];
                if(e == rowMin[i] && e == colMax[j]) {
                    ans.push_back(e);
                }
            }
        }

        return ans;
    }
};

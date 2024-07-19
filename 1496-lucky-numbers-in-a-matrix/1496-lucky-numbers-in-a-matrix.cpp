class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        for (int i = 0; i < matrix.size(); i++) {
            int row = INT_MAX;
            int ind = 0;
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] < row) {
                    row = matrix[i][j];
                    ind = j;
                }
            }
            int col = INT_MIN;
            for (int i = 0; i < matrix.size(); i++) {
                col = max(col, matrix[i][ind]);
            }
            if (row == col) {
                ans.push_back(row);
            }
        }
        return ans;
    }
};
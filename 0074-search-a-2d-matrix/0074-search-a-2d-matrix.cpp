class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();         // Number of rows
        int m = matrix[0].size();      // Number of columns
        int i = 0;                     // Start row index
        int j = m - 1;                 // Start column index (top-right corner)
        
        while (i < n && j >= 0) {
            if (matrix[i][j] == target) {
                return true;            // Found the target
            } else if (matrix[i][j] > target) {
                j--;                    // Move left
            } else {
                i++;                    // Move down
            }
        }
        return false;                   // Target not found
    }
};

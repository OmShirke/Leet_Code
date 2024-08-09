class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int i, int j) {
        vector<int> vals;
        for (int x = i; x < i + 3; ++x) {
            for (int y = j; y < j + 3; ++y) {
                vals.push_back(grid[x][y]);
            }
        }
        sort(vals.begin(), vals.end());
        for (int k = 0; k < 9; ++k) {
            if (vals[k] != k + 1) return false;
        }
        
        return (grid[i][j] + grid[i][j+1] + grid[i][j+2] == 15 &&
                grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] == 15 &&
                grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2] == 15 &&
                grid[i][j] + grid[i+1][j] + grid[i+2][j] == 15 &&
                grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] == 15 &&
                grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] == 15 &&
                grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] == 15 &&
                grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] == 15);
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n < 3 || grid[0].size() < 3) return 0;  // Grid is too small for a 3x3 square
        
        int count = 0;
        for (int i = 0; i <= n - 3; ++i) {
            for (int j = 0; j <= grid[i].size() - 3; ++j) {
                if (grid[i+1][j+1] == 5 && isMagic(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};

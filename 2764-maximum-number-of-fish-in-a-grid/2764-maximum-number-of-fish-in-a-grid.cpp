class Solution {
public:
    int exploreRegion(int row, int col, vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 0) return 0;
        int currentFish = grid[row][col];
        grid[row][col] = 0;
        currentFish += exploreRegion(row + 1, col, grid);
        currentFish += exploreRegion(row - 1, col, grid);
        currentFish += exploreRegion(row, col + 1, grid);
        currentFish += exploreRegion(row, col - 1, grid);
        return currentFish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), maxFish = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] != 0) {
                    maxFish = max(maxFish, exploreRegion(row, col, grid));
                }
            }
        }
        return maxFish;
    }
};
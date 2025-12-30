class Solution {
public:
    bool ismagic(vector<vector<int>>& grid, int i, int j) {
        unordered_map<int,int> mp;
        for (int x = i; x < i + 3; x++) {
            for (int y = j; y < j + 3; y++) {

                mp[grid[x][y]]++;
                if(mp[grid[x][y]]>1 || grid[x][y]>9 || grid[x][y]<1){
                    return false;
                }
            }
        }
        return (
            grid[i][j] + grid[i][j + 1] + grid[i][j + 2] == 15 &&
            grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] == 15 &&
            grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] == 15 &&
            grid[i][j] + grid[i + 1][j] + grid[i + 2][j] == 15 &&
            grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] == 15 &&
            grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] == 15 &&
            grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == 15 &&
            grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] == 15);
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int count=0;
        if(n<3 || grid[0].size()<3){
            return 0;
        }
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=grid[i].size()-3;j++){
                if(grid[i+1][j+1]==5 && ismagic(grid,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};
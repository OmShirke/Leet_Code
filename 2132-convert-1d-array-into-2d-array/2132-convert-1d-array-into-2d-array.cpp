class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            return {};
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < original.size(); ++i) {
            int a = i / n;
            int b = i % n;
            ans[a][b] = original[i];
        }
        return ans;
    }
};

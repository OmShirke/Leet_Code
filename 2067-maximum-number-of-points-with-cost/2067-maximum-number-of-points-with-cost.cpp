class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();

        // DP array initialized with the first row of points
        vector<long long> dp(points[0].begin(), points[0].end());

        for (int i = 1; i < n; ++i) {
            vector<long long> new_dp(m, 0);

            // Left to right pass to handle maximum value considering left-side transitions
            vector<long long> left(m, 0);
            left[0] = dp[0];
            for (int j = 1; j < m; ++j) {
                left[j] = max(left[j - 1] - 1, dp[j]);
            }

            // Right to left pass to handle maximum value considering right-side transitions
            vector<long long> right(m, 0);
            right[m - 1] = dp[m - 1];
            for (int j = m - 2; j >= 0; --j) {
                right[j] = max(right[j + 1] - 1, dp[j]);
            }

            // Update the dp array with the maximum of left and right transitions plus the current points
            for (int j = 0; j < m; ++j) {
                new_dp[j] = points[i][j] + max(left[j], right[j]);
            }

            dp = new_dp; // Move to the next row
        }

        // The result is the maximum value in the last dp row
        return *max_element(dp.begin(), dp.end());
    }
};


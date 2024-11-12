class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());

        for (int i = 1; i < items.size(); ++i) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(queries.size());
        int j = 0;
        for (const auto& [query, index] : sortedQueries) {
            while (j < items.size() && items[j][0] <= query) {
                ++j;
            }
            ans[index] = (j > 0) ? items[j - 1][1] : 0;
        }

        return ans;
    }
};

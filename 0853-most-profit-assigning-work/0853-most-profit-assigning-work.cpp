class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int m = difficulty.size();
        vector<pair<int, int>> arr(m);
        for (int a = 0; a < m; ++a) {
            arr[a] = {profit[a], difficulty[a]};
        }
        sort(arr.begin(), arr.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.second == b.second)
                     return a.first > b.first;
                 return a.second < b.second;
             });
        sort(worker.begin(), worker.end());
        int totalProfit = 0;
        int bestProfit = 0;
        int j = 0;
        for (int i = 0; i < worker.size(); ++i) {
            while (j < m && worker[i] >= arr[j].second) {
                bestProfit = max(bestProfit, arr[j].first);
                ++j;
            }
            totalProfit += bestProfit;
        }
        return totalProfit;
    }
};

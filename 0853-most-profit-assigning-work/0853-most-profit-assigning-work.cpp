#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m = difficulty.size();
        vector<pair<int, int>> arr(m);
        
        // Pairing profit and difficulty
        for (int a = 0; a < m; ++a) {
            arr[a] = {profit[a], difficulty[a]};
        }

        // Sort jobs by difficulty, then by profit if difficulties are the same
        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        });

        // Sort workers by their ability
        sort(worker.begin(), worker.end());

        int totalProfit = 0;
        int bestProfit = 0;
        int j = 0;

        // Traverse through each worker
        for (int i = 0; i < worker.size(); ++i) {
            // While the worker can perform the job, update the best profit
            while (j < m && worker[i] >= arr[j].second) {
                bestProfit = max(bestProfit, arr[j].first);
                ++j;
            }
            // Add the best possible profit for the current worker
            totalProfit += bestProfit;
        }

        return totalProfit;
    }
};

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if (n == 0) return 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int end = timeSeries[i] + duration;
            if (i < n - 1 && end > timeSeries[i + 1]) {
                end = timeSeries[i + 1];
            }
            ans += end - timeSeries[i];
        }
        return ans;
    }
};

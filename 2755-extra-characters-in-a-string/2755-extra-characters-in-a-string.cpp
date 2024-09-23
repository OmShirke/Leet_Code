class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);

            for (int j = i; j < n; ++j) {
                string sub = s.substr(i, j - i + 1);
                if (dict.find(sub) != dict.end()) {
                    dp[j + 1] = min(dp[j + 1], dp[i]);
                }
            }
        }

        return dp[n];
    }
};
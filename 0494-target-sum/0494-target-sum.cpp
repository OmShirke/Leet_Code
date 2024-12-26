class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (s > sum || (s + sum) & 1) return 0; 
        return subsetSum(nums, (s + sum) >> 1);
    }

    int subsetSum(vector<int>& nums, int s) {
        if (s < 0) return 0; 
        vector<int> dp(s + 1, 0);
        dp[0] = 1;
        for (int n : nums) {
            for (int i = s; i >= n; i--) {
                dp[i] += dp[i - n];
            }
        }
        return dp[s];
    }
};


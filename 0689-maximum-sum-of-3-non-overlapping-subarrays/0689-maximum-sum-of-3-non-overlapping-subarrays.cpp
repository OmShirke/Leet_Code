class Solution {
public:
    int memo[20000][4];
    vector<int> ret;
    int dp(int i, int n, int k, vector<int>& arr) {
        if (!n)
            return 0;
        if (i >= arr.size()) {
            if (n)
                return INT_MIN;
            else
                return 0;
        } else if (memo[i][n] != -1)
            return memo[i][n];
        else {
            int taken = 0, not_taken = 0;
            not_taken = dp(i + 1, n, k, arr);
            taken = arr[i] + dp(k + i, n - 1, k, arr);
            return memo[i][n] = max(taken, not_taken);
        }
    }
    void dfs(int i, int n, int k, vector<int>& arr) {
        if (!n)
            return;
        else {
            int taken = 0, not_taken = 0;
            taken = arr[i] + dp(i + k, n - 1, k, arr);
            not_taken = dp(i + 1, n, k, arr);
            if (taken >= not_taken) {
                ret.push_back(i);
                dfs(i + k, n - 1, k, arr);
            } else
                dfs(i + 1, n, k, arr);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> arr(nums.size() - k + 1);
        int sum = 0, j = 0;
        for (int i = 0; i < k; ++i)
            sum += nums[i];
        arr[j++] = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum -= nums[i - k];
            sum += nums[i];
            arr[j++] = sum;
        }
        memset(memo, -1, sizeof(memo));
        dp(0, 3, k, arr);
        dfs(0, 3, k, arr);
        return ret;
    }
};
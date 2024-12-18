class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices;
        int n=prices.size();
        int i = 0;
        while (i < n - 1) {
            int j = i + 1;
            if (prices[i] >= prices[j]) {
                ans[i] -= prices[j];
                i++;
                continue;
            } else {
                while (j < n) {
                    if (prices[i] >= prices[j]) {
                        ans[i] -= prices[j];
                        break;
                    }
                    j++;
                }
            }
            i++;
        }
        return ans;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, buy, sell, profit = 0, n=prices.size() - 1;
        while (i < n) {
            while (i < n && prices[i + 1] <= prices[i]) i++;
            buy = prices[i];

            while (i < n && prices[i + 1] > prices[i]) i++;
            sell = prices[i];

            profit += sell - buy;
        }
        return profit;
    }
};
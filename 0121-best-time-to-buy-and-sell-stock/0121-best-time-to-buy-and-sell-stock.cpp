class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
        int compare=0;
        for( int i=prices.size()-1;i>=0;i--){
            if(i!=0 && prices[i]>max){
               max=prices[i];
            }
            if(prices[i]<max && compare<max-prices[i]){
            compare=max-prices[i];
            }
        }
        return compare;
    }
};
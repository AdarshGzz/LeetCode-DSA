class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyPrice = prices[0];
        int maxProfit = 0;
        for(int i=0;i<n;i++){
            if(buyPrice>prices[i]){
                buyPrice = prices[i];
            }
            else if(prices[i]-buyPrice > maxProfit){
                maxProfit = prices[i]-buyPrice;
            }
        }
        return maxProfit;
    }
};
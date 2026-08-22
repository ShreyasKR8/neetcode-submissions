class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int i = 0;
        int resProfit = 0;

        while(i < prices.size()) {
            if(prices[i] < buy) {
                buy = prices[i];
                // i++;
            }
            else {
                int profit = prices[i] - buy;
                resProfit = max(profit, resProfit);
            }
            i++;
        }
        return resProfit;
    }
};

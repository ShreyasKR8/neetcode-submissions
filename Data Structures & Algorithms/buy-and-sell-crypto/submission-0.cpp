class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 1;
        int maxProfit = 0;

        while(j < prices.size()) {
            if(prices[j] > prices[i]) {
                maxProfit = max(prices[j] - prices[i], maxProfit);

            }
            else {
                i = j;
            }
            j++;
        }

        return maxProfit;
    }
};

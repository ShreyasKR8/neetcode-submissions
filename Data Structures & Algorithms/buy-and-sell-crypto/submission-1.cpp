//brute force cause what am I tryna solve here?
//i is the buying day and j is the selling day
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++) {
            for(int j = i + 1; j < prices.size(); j++) {
                if(prices[i] < prices[j]) {
                    maxProfit = max(maxProfit, prices[j] - prices[i]);
                }
            }
        }

        return maxProfit;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0,buy = prices[0];
        for(int i = 0; i < prices.size() ; i++)
        {
            if(buy > prices[i])
            buy = prices[i];
            else if(prices[i] - buy  > profit)
            profit = prices[i] - buy;
        }
        return profit;
    }
};
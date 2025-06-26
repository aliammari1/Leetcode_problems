// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int buy = prices[0], max_profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (buy > prices[i])
            buy = prices[i];
        else if (prices[i] - buy > max_profit)
            max_profit = prices[i] - buy;
    }
    return max_profit;
    }
};
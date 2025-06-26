// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> v;
        for(int i = 0; i < prices.size();i++)
            for(int j = i+1; j < prices.size();j++)
                v.push_back(prices[j]-prices[i]);
        int x = *max_element(v.begin(),v.end());
        return x > 0 ? x : 0 ;
    }
};
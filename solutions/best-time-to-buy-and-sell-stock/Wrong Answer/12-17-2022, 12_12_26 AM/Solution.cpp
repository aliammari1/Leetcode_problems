// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto it = min_element(prices.begin(),prices.end());
        int min = *it;
        int max = 0;
        it++;
        for(;it!=prices.end();it++)
            if(max < *it)
                max = *it;
        return  (max - min) > 0 ? max - min : 0;
    }
};
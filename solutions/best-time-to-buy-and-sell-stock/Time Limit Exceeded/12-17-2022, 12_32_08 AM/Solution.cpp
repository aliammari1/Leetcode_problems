// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> v;
        for(int i = 0; i < prices.size();i++)
            for(int j = i+1; j < prices.size();j++)
                v.push_back(prices[j]-prices[i]);
        sort(v.begin(),v.end());
        int size = v.size() - 1;
        if(size < 0)
            return 0;
        return v[size] > 0 ? v[size] : 0 ;
    }
};
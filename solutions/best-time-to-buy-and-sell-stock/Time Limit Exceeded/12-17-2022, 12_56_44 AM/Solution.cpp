// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        map<int,int> m;
        for(int i = 0; i < prices.size();i++)
            for(int j = i+1; j < prices.size();j++)
                m.insert(m.begin(),pair<int,int>(prices[j]-prices[i],i));
        int size = m.size() - 1;
        if(size < 0)
            return 0;
        return m.rbegin()->first > 0 ? m.rbegin()->first : 0 ;
    }
};
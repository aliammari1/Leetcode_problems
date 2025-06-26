// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> found(candies.size(),false);
        int max = *max_element(candies.begin(),candies.end());
        for(int i = 0;i < candies.size();i++)
            if(candies[i] + extraCandies >= max)
                found[i] = true;
        return found;
    }
};
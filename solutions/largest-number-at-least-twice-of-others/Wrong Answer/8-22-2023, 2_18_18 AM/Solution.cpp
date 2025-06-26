// https://leetcode.com/problems/largest-number-at-least-twice-of-others

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = *max_element(nums.begin(),nums.end()),maxIndex = 0;
        for(int i = 0;i < nums.size() - 1;i++)
        {
            if(nums[i] == max)
                maxIndex = i;
            else if(max < nums[i] * 2)
                return -1;
        }
        return maxIndex;
    }
};
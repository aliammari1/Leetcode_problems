// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int firstMax = 0, secondMax = 0, thirdMax = 0;
        int max = nums[0];
        vector<int> maxs(3,0);
        for(int i = 0;i < 3;i++)
        {
        for(int j = 0;j < nums.size();j++)
        {
            if(i == 0 && max < nums[i])
                max = nums[i];
            else if(i == 1 && max < nums[i] && nums[i] != maxs[i-1])
                max = nums[i];
            else if(i == 2 && max < nums[i] && nums[i] != maxs[i-2] && nums[i] != maxs[i-1])
                max = nums[i];
        }
        maxs[i] = max;
        max = 0;
        }
        return maxs[2];
    }
};
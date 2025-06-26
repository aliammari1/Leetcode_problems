// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int x=nums[0];
        int y=0;
        for(int i=1;i<nums.size();i++)
        {
        if(nums[i]+x!=target)
        {x = target - nums[i];
        y=i;
        }
        else
            return {y,i};
        }
        return {-1,-1};
    }
};
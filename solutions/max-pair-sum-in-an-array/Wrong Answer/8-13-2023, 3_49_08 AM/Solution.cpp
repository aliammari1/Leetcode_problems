// https://leetcode.com/problems/max-pair-sum-in-an-array

class Solution {
public:
    int maxSum(vector<int>& nums) {
    int max = -1;
    for(int i = 0;i < nums.size();i++)
    for(int j = 0;j < nums.size();j++)
    {
        int n1 = (nums[i] % 10) * 10 + (nums[i] / 10);
        if(n1 == nums[j] && n1 > max)
        max = nums[i] + nums[j];
    }
    return max;
    }
};
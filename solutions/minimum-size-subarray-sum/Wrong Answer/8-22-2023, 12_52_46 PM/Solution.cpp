// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int max = 0,maxIndex = -1,leftSum = 0,rightSum = 0,minimumSize = 0;
    for(int i = 0;i < nums.size();i++)
    if (nums[i] > max)
    {
        maxIndex = i;
        max = nums[i];
    }
    int start = maxIndex,end = maxIndex;
    while(start >= 0 || end < nums.size())
    {
        if(start >= 0)
        {
            leftSum += nums[start];
            start--;
        }
        if(end < nums.size())
        {
            rightSum += nums[end];
            end++;
        }
        minimumSize++;
        if(leftSum >= target)
            return minimumSize;
        if(rightSum >= target)
            return minimumSize;
    }
    return 0;
    }
};
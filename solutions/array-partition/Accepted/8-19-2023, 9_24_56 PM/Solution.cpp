// https://leetcode.com/problems/array-partition

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int maxSum = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i+=2)
            maxSum += min(nums[i],nums[i+1]);
        return maxSum;
    }
};
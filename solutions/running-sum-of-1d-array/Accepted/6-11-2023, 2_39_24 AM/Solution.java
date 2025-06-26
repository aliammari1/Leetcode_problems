// https://leetcode.com/problems/running-sum-of-1d-array

class Solution {
    public int[] runningSum(int[] nums) {
        int[] Sum = new int[nums.length];
        Sum[0] = nums[0];
        for(int i = 1; i < nums.length;i++)
        {
            Sum[i] += Sum[i-1] + nums[i];
        }
        return Sum;
    }
}
// https://leetcode.com/problems/running-sum-of-1d-array

class Solution {
    public int[] runningSum(int[] nums) {
        int[] Sum = new int[nums.length];
        for(int i = 0; i < nums.length;i++)
        {
            Sum[i] += (i < 1) ? nums[i] : Sum[i-1] + nums[i];
            System.out.print(nums[i]);
        }
        return Sum;
    }
}
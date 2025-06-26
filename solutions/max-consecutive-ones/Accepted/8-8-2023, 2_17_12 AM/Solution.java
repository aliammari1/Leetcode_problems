// https://leetcode.com/problems/max-consecutive-ones

class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0;
        int k = 0;
        for(int i = 0;i < nums.length;i++)
        {
            if(nums[i] == 1)
                max++;
            k  = max > k ? max : k;
            if(nums[i] == 0)
                max = 0;
        }
        return k;
    }
}
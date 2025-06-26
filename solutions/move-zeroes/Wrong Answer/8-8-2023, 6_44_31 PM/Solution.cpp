// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++)
            if(nums[i] == 0)
                for(int j = i;j < nums.size()-1;j++)
                {
                    int k = nums[i+1];
                    nums[i+1] = nums[i];
                    nums[i] = k;
                }
    }
};
// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writePointer = 0;
        for(int i = 0;i < nums.size();i++)
            if(nums[i] == 0)
                for(int j = i;j < nums.size();j++)
                    if(nums[j]!=0)
                    {
                        int k = nums[j];
                        nums[j] = 0;
                        nums[j-1] = k;
                        i--;
                        break;
                    }
    }
};
// https://leetcode.com/problems/monotonic-array

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int monotone = 0;
        if(nums[0] >= nums[1]) monotone = 1;
        else if(nums[0] <= nums[1]) monotone = 2;
        for(int i = 0;i < nums.size() - 1;i++)
        {
            if(monotone == 1 && nums[i] < nums[i+1])
                return false;
            else if(monotone == 2 && nums[i] > nums[i+1])
                return false;
        }
        return true;
    }
};
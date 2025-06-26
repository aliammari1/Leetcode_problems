// https://leetcode.com/problems/largest-perimeter-triangle

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int m = 0;
        if(nums.size() >= 3)
            for(int i = 0;i < nums.size() - 2;i++)
            {
                if(nums[i] + nums[i+1] > nums[i+2]  && nums[i] + nums[i+2] > nums[i+1] && nums[i+2] + nums[i+1] > nums[i] && m < nums[i] + nums[i+1] + nums[i+2])
                m = nums[i] + nums[i+1] + nums[i+2];
            }

        return m;
    }
};
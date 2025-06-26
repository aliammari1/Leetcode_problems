// https://leetcode.com/problems/largest-perimeter-triangle

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int m = 0;
        if(nums.size() >= 3)
            for(int i = 0;i < nums.size() - 2;i++)
            for(int j = i + 1;j < nums.size() - 1;j++)
            for(int k = j + 1;k < nums.size();k++)
                if(nums[i] + nums[j] > nums[k]  && nums[i] + nums[k] > nums[j] && nums[k] + nums[j] > nums[i] && m < nums[i] + nums[j] + nums[k])
                m = nums[i] + nums[j] + nums[k];

        return m;
    }
};
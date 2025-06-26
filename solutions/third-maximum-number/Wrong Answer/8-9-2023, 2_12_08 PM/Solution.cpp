// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size() < 3) return *max_element(nums.begin(),nums.end());
        sort(nums.rbegin(),nums.rend());
        int i = 2;
        for(;i < nums.size();i++)
            if(nums[i] != nums[i - 1])
                break;
        return nums[i];
    }
};
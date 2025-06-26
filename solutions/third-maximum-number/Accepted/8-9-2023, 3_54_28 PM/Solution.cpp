// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k = 1;
        int i = nums.size() - 1;
        for(;i > 0;i--)
        {
            if(k == 3)
                break;
            if(nums[i]!=nums[i-1])
                k++;
        }
        return k == 3 ? nums[i] : *max_element(nums.begin(),nums.end());
    }
};
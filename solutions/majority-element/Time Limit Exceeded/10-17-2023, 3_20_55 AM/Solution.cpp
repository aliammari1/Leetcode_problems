// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0,n = 0;
        for(int i = 0;i < nums.size();i++)
        {
            n = count(nums.begin(),nums.end(),nums[i]); 
            if(n > nums.size() / 2)
            {
                majority = nums[i];
                break;
            }
        }
        return majority;
    }
};
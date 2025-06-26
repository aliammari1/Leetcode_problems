// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0,n = 0,size = nums.size();
        for(int i = 0;i < size;i++)
        {
            n = count(nums.begin(),nums.end(),nums[i]); 
            if(n > size / 2)
            {
                majority = nums[i];
                break;
            }
        }
        return majority;
    }
};
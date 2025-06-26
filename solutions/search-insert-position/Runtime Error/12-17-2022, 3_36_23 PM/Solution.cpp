// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0;
        int last = nums.size()-1;
        for(int i = 0;i<nums.size();i++)
        {
            int index = (last+beg)/2;
            if(nums[index]>target)
            last = index - 1;
            else if(nums[index]<target)
            beg = index + 1;
            if(nums[index]>target && nums[index - 1]<target)
            return index;
            if(nums[index]==target)
            return index;
        }
        return nums.size();
    }
};
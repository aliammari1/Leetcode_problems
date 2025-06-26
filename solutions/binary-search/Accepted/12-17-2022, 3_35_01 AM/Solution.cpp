// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int last = size-1;
        int beg = 0;
        while(beg<=last)
        {
            int index = (last + beg) / 2;
            if(nums[index]>target)
            last = index - 1;
            else if(nums[index]<target)
            beg = index + 1;
            else
            return index;
        }
        return -1;
    }
};
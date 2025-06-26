// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[0] == target) return 0;
        if(nums[nums.size() - 1] == target) return nums.size() - 1;
        int start = 0, end = nums.size() - 1, mid = 0;
        while(start < end)
        {
            mid = (start + end) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end = mid;
            else if(nums[mid] < target)
                start = mid + 1;
        }
        return -1;
    }
};
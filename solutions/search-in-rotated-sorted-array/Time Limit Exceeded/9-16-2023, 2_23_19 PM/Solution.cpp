// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        if(nums[start]  == target)
            return start;
        if(nums[end]  == target)
            return end;
        if(nums[start] > target && nums[end] < target)
            return -1;
        while(start < end && start>= 0 && end <= nums.size() -1)
        {
            int mid = (start + end) / 2;
            if(nums[start]  == target)
                return start;
            if(nums[end]  == target)
                return end;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
            start = mid - 1;
            else if(nums[mid] < target)
            end = mid + 1;
            // cout << "start "<< nums[start]<< " end " << nums[end]<< " mid " << nums[mid] << endl;
        }
        return -1;
    }
};
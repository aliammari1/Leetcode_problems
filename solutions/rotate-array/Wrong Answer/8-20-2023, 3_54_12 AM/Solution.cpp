// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 1 || size == k || size % k == 0) return;
        k = k % size;
        k = size - k;
        for(int i = 0;i < k;i++)
            for(int j = 0;j < size-1;j++)
                swap(nums[j],nums[j+1]);
    }
};
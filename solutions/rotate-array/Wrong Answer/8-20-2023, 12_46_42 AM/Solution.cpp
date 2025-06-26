// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % 2 ? k+1 : k;
        for(int i = 0;i < k;i++)
            for(int j = 0;j < nums.size()-1;j++)
                swap(nums[j],nums[j+1]);
    }
};
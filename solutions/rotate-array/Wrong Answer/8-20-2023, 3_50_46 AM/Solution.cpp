// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 1 || nums.size() == k) return;
        int size = nums.size() - k;
        cout << size << endl;
        for(int i = 0;i < size;i++)
            for(int j = 0;j < nums.size()-1;j++)
                swap(nums[j],nums[j+1]);
    }
};
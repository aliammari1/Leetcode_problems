// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = 0;
        int size = nums.size();
        for(int i = 0;i < size - 2;i++)
        {
            if(nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
            {
                size--;
                for(int j = i + 2;j < size;j++)
                    swap(nums[j],nums[j+1]);
                i--;
                n++;
            }
        }
        return size;
    }
};
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = 0;
        for(int i = 0;i < nums.size()-2;i++)
        {
            if(nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
            {
                for(int j = i + 2;j < nums.size()-1;j++)
                    swap(nums[j],nums[j+1]);
                i--;
                n++;
            }
        }
        return nums.size() - n;
    }
};
// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int found = 0;
        int value = 0;
        for(int i = 0;i < nums.size();i++)
        {
            value = nums[i];
            found = 0;
            for(int j = 0;j < nums.size();j++)
            {
                if(found == 1 && nums[j] == value)
                    nums.erase(nums.begin()+j,nums.begin()+j+1);
                else if(nums[j] == value)
                    found = 1;
            }
        }
        return nums.size();
    }
};
// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        for(auto i = 0;i < k;i++)
            if(nums[i] == val)
                {
                    nums.erase(nums.begin()+i);
                    i--;
                    k--;
                }
        return k;
    }
};
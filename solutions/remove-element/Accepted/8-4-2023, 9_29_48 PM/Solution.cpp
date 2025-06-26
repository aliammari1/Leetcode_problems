// https://leetcode.com/problems/remove-element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        for(auto i = 0;i < nums.size();i++)
            if(nums[i] == val)
                {
                    for(auto j = i;j < nums.size() - 1;j++)
                        nums[j] = nums[j+1];
                    nums.pop_back();
                    nums.push_back(-1);
                    k--;
                    i--;
                }
        return k;
    }
};
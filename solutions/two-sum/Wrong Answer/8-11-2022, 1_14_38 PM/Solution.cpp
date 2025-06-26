// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp(0);
        for(int i=0;i<nums.size()-2;i++)
            for(int j=i+1;j<nums.size()-1;j++)
                if(nums[i]+nums[j] == target)
                {
                    temp.push_back(i);
                    temp.push_back(j);
                }
        return temp;
    }
};
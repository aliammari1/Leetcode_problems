// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for(auto i=0;i<nums.size();i++)
        {
            if(m.find(target - nums[i]) != m.end())
                return {m.find(target - nums[i])->second,i};
            m[nums[i]]=i;
        }
        return {-1,-1};
    }
};
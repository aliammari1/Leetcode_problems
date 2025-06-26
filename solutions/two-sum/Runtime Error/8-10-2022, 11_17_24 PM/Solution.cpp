// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp(0);
        int j=1;
        for(int i=0;i<nums.size();i++)
        {
            if(j<nums.size()-1)
            j++;
            else
            j=i+1;
            
            if(nums[i] + nums[j] == target)
                {
                    temp.push_back(i);
                    temp.push_back(j);
                }
            
        }
        return temp;
        
    }
};
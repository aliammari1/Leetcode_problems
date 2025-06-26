// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missed;
        bool found = false;
        for(int i = 0;i < nums.size();i++)
        {
            found = false;
            int j = i;
            for(; j < nums.size();j++)
                if(nums[i]==j+1)
                {
                found = true;
                break;
                }
            if(!found) missed.push_back(i+1);
        }
        return missed;
    }
};
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missed;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++)
            if(!binary_search(nums.begin(),nums.end(),i+1)) 
                missed.push_back(i+1);
        return missed;
    }
};
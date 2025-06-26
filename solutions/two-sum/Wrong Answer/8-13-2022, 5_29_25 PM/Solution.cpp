// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int beg=0,end=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(beg<end)
        {
        int sum = nums[beg] + nums[end];
        if(sum==target)
        return {beg,end};
        else if(sum>target)
        end--;
        else
        beg++;
        }
        
        return {-1,-1};
    }
};
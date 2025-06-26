// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int index = nums.size() - 1;
        while(index >= 0)
        {
            if(accumulate(nums.begin()+index,nums.end(),0)>=target);
            return nums.size() - index + 1;
            index--;
        }
        return 0;
    }
};
// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int index = 0;
        int size = nums.size();
        while(index < size)
        {
            if(accumulate(nums.end()-index-1,nums.end(),0)  >=  target)
                return ++index;
            index++;
        }
        return 0;
    }
};
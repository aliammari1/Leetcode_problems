// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int index = 0;
        int size = nums.size();
        while(index < size)
        {
            cout << accumulate(nums.end()-index-1,nums.end(),0) << endl;
            if(accumulate(nums.begin()+index,nums.end(),0)>=target);
            return index + 1;
            index++;
        }
        return 0;
    }
};
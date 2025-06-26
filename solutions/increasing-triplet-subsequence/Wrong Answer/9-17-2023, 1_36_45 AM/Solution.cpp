// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) return false;
        int i = 0,j = i +1, k = j + 1;
        while(k < nums.size())
        {
           if(nums[i] < nums[j] && nums[j] < nums[k])
                return true;
            i++;
            j++;
            k++;
        }
        return false;
    }
};
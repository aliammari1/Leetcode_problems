// https://leetcode.com/problems/sort-array-by-parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++)
            if(nums[i]%2 != 0)
                for(int j = i+1;j < nums.size();j++)
                    if(nums[j]%2 == 0)
                    {
                        int k = nums[i];
                        nums[i] = nums[j];
                        nums[j] = k;
                        i--;
                        break;
                    }
        return nums;
    }
};
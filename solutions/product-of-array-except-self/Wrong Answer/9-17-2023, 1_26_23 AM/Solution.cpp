// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1,n = 0;
        bool zeroFound = false;

        for(int i = 0;i < nums.size();i++)
        {   if(nums[i] != 0)
                product *= nums[i];
            else
                {
                    zeroFound = true;
                    n++;
                }
        }
        if(zeroFound)
        {
            int j = 0;
            for(int i = 0;i < nums.size();i++)
            {
                if(nums[i] != 0 || n > 1)
                    nums[i] = 0;
                else
                {
                        nums[i] = product - (product * j / (j + 1));
                        j++;
                }
            }
        }
        else
        {
        for(int i = 0;i < nums.size(); i++)
        {
            nums[i] = product - (product * i / (i + 1));
        }
        }
        return nums;
    }
};
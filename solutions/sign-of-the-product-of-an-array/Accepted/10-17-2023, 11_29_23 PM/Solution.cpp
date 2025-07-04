// https://leetcode.com/problems/sign-of-the-product-of-an-array

class Solution {
public:
    int signFunc(int number)
    {
        if(number > 0)
            return 1;
        if(number < 0)
            return -1;
        return 0;
    }
    int arraySign(vector<int>& nums) {
        int product = 1;
        for(int i = 0;i < nums.size();i++)
            product *= signFunc(nums[i]);
        return product;
    }
};
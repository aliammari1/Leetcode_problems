// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> v1(nums.begin(),nums.begin()+nums.size()-k),v2(nums.end()-k,nums.end());
        nums.clear();
        nums.insert(nums.begin(),v2.begin(),v2.end());
        nums.insert(nums.end(),v1.begin(),v1.end());
    }
};
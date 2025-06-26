// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAverage = -10000,average = -10000;
        for(int i = 0;i < nums.size() - k + 1;i++)
        {
            average = accumulate(nums.begin()+i,nums.begin()+i+k,0) / (double) k;
            if(average > maxAverage)
            maxAverage = average;
        }
        return maxAverage;
    }
};
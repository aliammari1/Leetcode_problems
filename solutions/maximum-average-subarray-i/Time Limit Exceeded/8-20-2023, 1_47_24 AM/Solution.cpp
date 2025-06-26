// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAverage = -10000,size = nums.size();
        int j = k;
        for(int i = 0;i < size  - k + 1;i++)
        {
            double average = accumulate(nums.begin()+i,nums.begin()+j,0) / (double) k;
            if(average > maxAverage)
            maxAverage = average;
            j++;
        }
        return maxAverage;
    }
};
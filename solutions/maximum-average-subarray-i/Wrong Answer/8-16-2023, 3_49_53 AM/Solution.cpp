// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAverage = 0.0,average = 0.0;
        int j = 0;
        for(int i = j;i < nums.size() - k + 1;i++)
        {
            average = accumulate(nums.begin()+j,nums.begin()+j+k,0) / (double) k;
            if(average > maxAverage)
            maxAverage = average;
            j++;
        }
        return maxAverage;
    }
};
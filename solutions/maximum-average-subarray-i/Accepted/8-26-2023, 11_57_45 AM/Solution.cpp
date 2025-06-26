// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAverage = -10000,size = nums.size();
        double average = accumulate(nums.begin(),nums.begin()+k,0);
        int end = k-1,start = 0;
        while(end != nums.size())
        {
            cout << average << endl;
            if(average /(double) k > maxAverage)
                maxAverage = average/(double) k;
            average -= nums[start];
            start++;
            end++;
            if(end == nums.size())
                break;
            average += nums[end];
        }
        return maxAverage;
    }
};
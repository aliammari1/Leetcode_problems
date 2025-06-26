// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    if(accumulate(nums.begin(),nums.end(),0) < target) return 0;
    int start = 0,end = 0,min = nums.size()-1,max = 0;
    while(start != nums.size())
    {
        max = accumulate(nums.begin()+start,nums.begin()+end,0);
        cout << max << endl;
        cout << "---------------- " << start << " " << end << " -------------------" << endl;
        if(max < target && end == nums.size())
            break;
        if(min > end-start && max >= target)
        {
            cout << start << " " << end << endl;
            min = end-start;
        }
        if(max >= target)
            start++;
        else
            end++;
            
    }
    return min;
    }
};
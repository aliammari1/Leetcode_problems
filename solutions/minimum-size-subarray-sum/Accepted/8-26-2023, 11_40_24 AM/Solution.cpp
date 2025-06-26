// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    if(accumulate(nums.begin(),nums.end(),0) < target) return 0;
    int start = 0,end = 0,min = nums.size(),sum = nums[start];
    while(start != nums.size())
    {
        cout << "---------------- " << start << " " << end << " -------------------" << endl;
        cout << sum << endl;
        if(sum < target && end == nums.size())
            break;
        if(min > end-start+1 && sum >= target)
        {
            cout << "min: " << start << " " << end << endl;
            min = end-start+1;
        }
        if(sum >= target)
        {
            sum-=nums[start];
            start++;
        }
        else
        {
            end++;
            if(end==nums.size())
                break;
            sum+=nums[end];
        }
            
    }
    return min;
    }
};
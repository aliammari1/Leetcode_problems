// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int start = 0,end = nums.size() - 1,leftSum = 0,rightSum = 0,found = 0;
        while(start <= end)
        {
            if(leftSum > rightSum)
            {
                rightSum += nums[end];
                end--;
            }
            else if(leftSum < rightSum)
            {
                leftSum += nums[start];
                start++;
            }
            else if(leftSum == rightSum && start == end)
            {
                found = 1;
                break;
            }
            else if(leftSum == rightSum)
            {
                rightSum += nums[end];
                leftSum += nums[start];
                end--;
                start++;
            }
            cout << start << " " << leftSum << " " << end << " " << rightSum << endl;
        }
        if(rightSum == 0)
            return 0;
        if(leftSum == 0)
            return nums.size() - 1;
        if(leftSum == rightSum && found)
            return start;
        return -1;
    }
};
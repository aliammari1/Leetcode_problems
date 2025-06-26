// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int counter = 1;
        int i = 0;
        while(i < n)
        {  
            if(nums[i] == counter)
            {
            nums.erase(nums.begin()+i);
            i--;
            n--;
            if( i + 1 < n && nums[i+1] >= counter + 1) counter++;
            }
            else
            {
            nums.push_back(counter);
            counter++;
            if( i + 1 < n && nums[i+1] != counter) i--;
            }
            i++;
        }
        return nums;
    }
};
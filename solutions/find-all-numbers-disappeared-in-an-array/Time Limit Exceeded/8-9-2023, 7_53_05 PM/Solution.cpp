// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missed;
        vector<bool> found(nums.size(),false);
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++)
        {
            int j = 0;
            for(; j < nums.size();j++)
                if(nums[j]==i+1)
                {
                found[i] = true;
                break;
                }
            cout << i << " " << j << " " << found[i] << endl;
            if(!found[i]) missed.push_back(i+1);
        }
        return missed;
    }
};
// https://leetcode.com/problems/determine-the-minimum-sum-of-a-k-avoiding-array

class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int> v;
        int j = 0,sum = 0;
        for(int i = 0;i < n;i++)
            if(find(v.begin(),v.end(),k - j + 1) != v.end())
                v.push_back(++j);
        return accumulate(v.begin(),v.end(),0);
        
    }
};
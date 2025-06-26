// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        vector<vector<int>> v(numRows);
        v[0] = {1};
        v[1] = {1,1};
        for(int i = 2;i < numRows;i++)
        {
        for(int j=0;j <= i;j++)
        {
        if(j == i)
        {
            v[i].push_back(v[i-1][j-1]);
        }
        else if(j - 1 < 0)
        {
            v[i].push_back(v[i-1][j]);
        }
        else
        {
            v[i].push_back(v[i-1][j] + v[i-1][j-1]);
        }
        }
        }
        return v;   
    }
};
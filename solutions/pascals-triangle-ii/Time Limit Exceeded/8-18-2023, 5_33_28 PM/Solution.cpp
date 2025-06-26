// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    
    int pascal(int rowIndex, int j)
    {
        if(rowIndex == 0 || j == 0 || j == rowIndex-1) 
            return 1;
        return pascal(rowIndex - 1,j) + pascal(rowIndex - 1,j-1);
    }
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        for(int i = 0;i <= rowIndex;i++)
            v.push_back(pascal(rowIndex+1,i));
        return v;
    }
};
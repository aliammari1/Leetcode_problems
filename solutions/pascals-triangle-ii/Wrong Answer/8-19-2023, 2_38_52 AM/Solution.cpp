// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    
    int pascal(int rowIndex, int j)
    {
        if(rowIndex == 0 || j == 0 || j == rowIndex-1) 
            return 1;
        int p1 = pascal(rowIndex - 1,j-1);
        int p2 = pascal(rowIndex - 1,j);
        return p1 + p2;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        int size = ceil((rowIndex+1) / (double)2);
        int val = 0;
        for(int i = 0;i < size;i++)
        {
            val =pascal(rowIndex+1,i); 
            v.insert(v.begin()+i,val);
            if(i != size - 1)
            v.insert(v.end()-i,val);
            else if(i == size - 1 && size % 2 == 0)
            v.insert(v.end()-i,val);
        }
        return v;
    }
};
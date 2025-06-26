// https://leetcode.com/problems/diagonal-traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.size()==1) return mat[0];
        vector<int> v;
        int i = 0,j = 0,k = 1;
        while(v.size() != mat.size() * mat[0].size())
        {
            while((j >=0 && i >= 0 && i < mat.size() && j < mat[0].size()))
            {
                cout << "before: " << i << " " << j << endl;
                v.push_back(mat[i][j]);
                if(k % 2 == 0)
                {
                    j--;
                    i++;
                }
                else
                {
                    j++;
                    i--;
                }
            }
            if((i <= 0 && j == mat[0].size()) || j == mat[0].size())
            {
                i+=2;
                j--;
            }
            if((i == mat.size() && j <= 0) || i == mat.size())
            {
                i--;
                j+=2;
            }
            if(i < 0)
                i = 0;
            if(j < 0)
                j = 0;
            k++;
        }
        return v;
    }
};